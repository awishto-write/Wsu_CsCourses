
# # Define the path to the StrangeSystem executable
# #executable_path = "./StrangeSystem-ARM"
# executable_path = "./StrangeSystem"

# # Define the target WSU ID
# wsu_id = "11755265"  # Use your WSU ID here

# # Define the number of bits in the PIN code
# pin_length = 32


#

# from pwn import *
# import time

# # Define the command for the StrangeSystem executable
# command = './StrangeSystem'

# # Create a process using the provided command
# try:
#     proc = process(command)
# except Exception as e:
#     print(f"Error starting process: {e}")
#     exit(1)

# # Log in with your WSU ID
# proc.sendline(b"11755265")  # Replace with your WSU ID

# # Wait for the prompt asking for the pincode
# try:
#     proc.recvuntil("Enter your 32-bits PIN code (in binary form like PIN in pincode.log): ")
# except EOFError:
#     print("EOFError: Process closed unexpectedly.")
#     exit(1)

# # Initialize the guessed PIN
# guessed_pin = ''

# # Iterate through each bit position from 0 to 31
# for i in range(32):
#     # Guess '0' for the current bit position
#     guess0 = guessed_pin + '0' + '0' * (31 - i)
#     start_time = time.time()
#     try:
#         proc.sendline(guess0.encode())
#         response0 = proc.recvline(timeout=1)
#     except EOFError:
#         print("EOFError during '0' guess.")
#         exit(1)
#     end_time = time.time()
#     time0 = end_time - start_time
    
#     # Guess '1' for the current bit position
#     guess1 = guessed_pin + '1' + '0' * (31 - i)
#     start_time = time.time()
#     try:
#         proc.sendline(guess1.encode())
#         response1 = proc.recvline(timeout=1)
#     except EOFError:
#         print("EOFError during '1' guess.")
#         exit(1)
#     end_time = time.time()
#     time1 = end_time - start_time
    
#     # Determine the correct bit based on verification time
#     if time0 < time1:
#         guessed_pin += '0'
#     else:
#         guessed_pin += '1'
    
#     # Clear the process buffer
#     proc.clean()

# # Print the final guessed PIN
# print("Guessed PIN:", guessed_pin)

# # Submit the final guess and receive the secret value
# try:
#     proc.sendline(guessed_pin.encode())
#     response = proc.recvall(timeout=1)
#     print(response)
# except EOFError:
#     print("EOFError during final submission.")
#     exit(1)

# # Close the process
# proc.close()




        ###


## CURRENT TIME, TOTAL TIME, CURRENT BIT, loop running through it, walking through the bits and interact with the 
## process thing  ## walking through that while loop Time it takes for things to finish, to run to stop, the bits digits of things
## Make use of the interacting process thing, he gave us and use it, .clean() is used also
## Think about what would happen as well as the time it would take to get a correct digit and if the time would be the same for every digit

##

# from pwn import *
# #command = ’/home/seed/Desktop/share/Final HW/CanvasHW/StrangeSystem’
# command = './StrangeSystem'
# proc = process(command)

# # Log in
# proc.sendline(b"11755265")
# print(proc.recvuntil("Enter your 32 - bits PIN code (in binary form like PIN in pincode.log ) : " ) )

# # You can use proc . interactive () to communicate with the process
# proc.clean()
# proc.sendline(b"0"*32)
# proc.interactive()
# # You can also use proc . recvline () , proc . recvall () , etc . Google and read the official tutorial for pwntools
# print(proc.recvall(timeout = 1))
# proc.close () # Close the process when done

##

# from pwn import *
# import time

# # Path to the StrangeSystem binary
# command = './StrangeSystem'

# # Create a process to interact with the system
# proc = process(command)

# # Log in with your WSU ID
# wsu_id = "11755265"  # Update with your own WSU ID
# proc.sendline(wsu_id.encode())

# # Receive and print the response to confirm your name is returned
# response = proc.recvuntil(b"Enter your 32-bits PIN code (in binary form like PIN in pincode.log):")
# print(response.decode())

# # Function to measure processing time for each bit in a given PIN guess
# def measure_time_per_bit(pin_guess):
#     times_per_bit = []
    
#     # Iterate through each bit in the PIN guess
#     for i in range(len(pin_guess)):
#         # Create a string for the guess up to the current bit
#         current_guess = pin_guess[:i + 1]
        
#         # Start measuring time
#         start_time = time.time()
        
#         # Send the current guess to the system
#         proc.sendline(current_guess.encode())

#         # Try to receive a response and measure time
#         try:
#             # Attempt to read a response
#             response = proc.recv(timeout=10)
#         except EOFError:
#             print(f"EOFError encountered at bit {i}. Process may have terminated early.")
#             times_per_bit.append(None)
#             continue  # Skip the rest of the loop iteration

#         # Calculate the time taken for the current guess
#         processing_time = time.time() - start_time
        
#         # Append the processing time for the current bit
#         times_per_bit.append(processing_time)
        
#     return times_per_bit

# # Example PIN guess (you can change this to your desired guess)
# pin_guess = "00000000000000000000000000000000"  # 32-bit PIN guess

# # Measure the processing time for each bit in the PIN guess
# times_per_bit = measure_time_per_bit(pin_guess)

# # Print the processing times for each bit
# for i, time_taken in enumerate(times_per_bit):
#     if time_taken is not None:
#         print(f"Time taken to process bit {i}: {time_taken:.6f} seconds")
#     else:
#         print(f"Failed to process bit {i}")

# # Close the process when done
# proc.close()


#

from pwn import *

# Path to the StrangeSystem binary
command = './StrangeSystem'

# Create a process to interact with the system
proc = process(command)

# Log in with your WSU ID
wsu_id = "11755265"  # Update with your own WSU ID
proc.sendline(wsu_id.encode())

# Receive and print the response to confirm your name is returned
response = proc.recvuntil(b"Enter your 32-bits PIN code (in binary form like PIN in pincode.log):")
print(response.decode())

# Function to extract the secret PIN from memory
def extract_secret_pin():
    # This function needs to be customized based on your reverse engineering findings
    # You need to know where the secret PIN is stored in memory

    # For the purpose of demonstration, let's assume you know the memory address
    # where the secret PIN is stored (replace 'memory_address' with the actual address)
    memory_address = 0x12345678  # Example memory address

    # Read the secret PIN from the memory address
    secret_pin = proc.read(memory_address, 4)  # Read 4 bytes (32 bits)
    
    # Convert the secret PIN to binary
    secret_pin_binary = bin(int.from_bytes(secret_pin, 'big'))[2:].zfill(32)
    
    return secret_pin_binary

# Extract the secret PIN
secret_pin = extract_secret_pin()
print(f"Secret PIN: {secret_pin}")

# Close the process when done
#proc.close()
