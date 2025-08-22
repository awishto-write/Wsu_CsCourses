#include "craps.h"

// 0. Welcoming

void welcome(void)
{
    printf("******************************************\n");
    printf("* ******  *****    ****   *****    ***** *\n");
    printf("* *       *    *  *    *  *    *  *      *\n");
    printf("* *       *****   ******  *****    ****  *\n");
    printf("* *       *    *  *    *  *            * *\n");
    printf("* ******  *    *  *    *  *       *****  *\n");
    printf("******************************************\n");
    printf("\n\n");
}

// 1. Display the game's menu

void print_game_menu(void)
{   
    printf("---------------------------------------------------------\n");
    printf("Choose an option(number) from the elements below: \n\n");

    printf("1: Display the game's rules. \n");
    printf("2. Enter the initial bank balance. \n");
    printf("3. Play the game. \n");
    printf("4. Exit. \n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");

    return;
}

// 2. Choosing an option

int get_option()
{
    int option = 0;
    scanf("%d", &option);
    return option;
}

// 3. Validation of the selected option

int print_and_validate(int option)
{
    int validate = 0;

    if ((option == 1) || (option == 2) || (option = 3) || (option = 4))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


// 4. Display the game's rules

void print_game_rules(void)
{
    printf("Welcome to the game of chance 'CRAPS'! \n\n");
    printf("Do you believe in luck or do you have a stragety for everything? \n\n");

    printf("1. Roll two dice. Each die has six faces. These faces contain 1, 2, 3, 4, 5, and 6 spots.\n");
    printf("2. After the dice have come to rest, the sum of the spots on the two upward faces is calculated.\n");
    printf("3. If the sum is 7 or 11 on the first throw, the player wins.\n\n");

    printf("4. If the sum is 2, 3, or 12 on the first throw, the player loses.\n");
    printf("5.If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's point.\n");
    printf("6.To win, you must continue rolling the dice until you make your point.\n");
    printf("7.The player loses by rolling a 7 before making the point.\n\n");
    
    printf("GOOD LUCK! And, certainly have fun! \n");

    return;
}

//5. Input the bank balance

double get_bank_balance(void)
{
    double balance = 0.0;

    printf("Pick a bank balance ($):\n");
    scanf("%lf", &balance);
    return balance;
}

// 6. Pick the wager amount

double get_wager_amount(void)
{
    double wager = 0.0;

    printf("You will soon pick a wager's amount. Make sure that it is valid (not negative) and less than your bank balance\n\n");
    printf("Pick a wager's amount ($): \n");
    scanf("%lf", &wager);
    return wager;
}

// 7. Checking to see if the wager's amount is within the reach of the bank balance

int check_wager_amount(double wager, double balance)
{
    if (wager < balance && wager >= 0)
    {
        printf("Your wager's amount is within your bank balance\n\n");
        return 1;
    }

    else
    {
        printf("Your wager's amount is out of reach\n\n");
        return 0;
    }
}

// 8. Rolling of a die

int roll_die(void)
{
    int roll = 0;

    roll = (rand() % 6) + 1;

    return roll;
}

// 9. Displaying the die rolled
 
void display_die(int die1, int die2)
{
    printf("Let the system pick random values for the dice\n\n");

    printf("die1 = %d\n\n", die1);
    printf("die2 = %d\n\n", die2);
    
 }

 // 10. Calculation of the dice's sum

int calculate_sum_dice(int die1_value, int die2_value)
{
    int sum_dice = 0;
    sum_dice = die1_value + die2_value;
    printf("The sum of the dice rolled is: %d\n\n", sum_dice);

    return sum_dice;
 }
     
// 11.  Did you win, loss or did you your sum lead you to points? 

int is_win_loss_or_point(int sum_dice)
{
    
    if (sum_dice == 7 || sum_dice == 11)
    {
        printf("You won! Craps!\n\n");
        return 1;
    }
    else if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12)
    {
        printf("You lost! The 'house' won!\n\n");
         return 0;
    }
    else
    {
       
        printf("The sum of your dice becomes your points\n");
        printf("Point value: %d\n\n", sum_dice);
        return -1;
    }
}


// 12. Is point loss or neither?

int is_point_loss_or_neither(int sum_dice, int point_value)
{
    int point_loss_neither = 0;

    if (sum_dice == point_value)
    {
        point_loss_neither = 1;
    }
    else if (sum_dice == 7)
    {
        point_loss_neither = 0;
    }
    else
    {
        point_loss_neither= -1;
    }

    return point_loss_neither;
}


// 13. Adjusted bank balance

double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract)
{
    if (add_or_subtract == 1)
    {
        bank_balance += wager_amount;
    }
    if (add_or_subtract == 0)
    {
        bank_balance -= wager_amount;
    }
    
        return bank_balance;
}

// 14. Calculation of the result

int calculate_result(int number_rolls, int sum_dice, int point_value)
{
    int result = 0;
    if (number_rolls == 0)
    {
        result = is_win_loss_or_point(sum_dice);
    }
    else if (number_rolls > 0 )
    {
        result = is_point_loss_or_neither(sum_dice,point_value);
    }
    return result;
}

// 15. Display the new bank balance

void check_bank_balance(double bank_balance)
{
    printf("Now, your new balance is : %lf\n\n", bank_balance);
}

// 16. Display chatter messages

void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance)
{
    if (number_rolls > 12)
    {
        printf("You played for a long time!\n");
    }
    if (win_loss_neither == 1)
    {
        printf("YAYYY! You won!\n");
    }
    if (win_loss_neither == 0)
    {
        printf("NOOOOOO! You lost!\n");
    }
    if (win_loss_neither == 0)
    {
        printf("You were close! You can play again!\n");
    }
    if (current_bank_balance > initial_bank_balance )
    {
        printf("You are doing good!\n");
    }

}
