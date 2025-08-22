#include <iostream>
#include <map>    // map<key, value>
#include "TwitterData.hpp"
using namespace std;

int main() {
    //std::cout << "Hello, World!" << std::endl;

    // Schema: UserName,Last,First,Email,NumTweets,MostViewedCategory
    string raw_data[5][6] = {{"rangerPower", "Smit",     "Rick",    "smitRick@gmail.com", "1117", "power lifting"},
                             {"kittyKat72",  "Smith",    "Kathryn", "kat@gmail.com",      "56",   "health"},
                             {"lexi5",       "Anderson", "Alexis",  "lexi5@gmail.com",    "900",  "education"},
                             {"savage1",     "Savage",   "Ken",     "ksavage@gmail.com",  "17",   "president"},
                             {"smithMan",    "Smith",    "Rick",    "rick@hotmail.com",   "77",   "olympics"}};
    TwitterData *twitter_data = new TwitterData[5];
    for (int i = 0; i < 5; ++i) {
        twitter_data[i].setUserName(raw_data[i][0]);
        twitter_data[i].setActualName(raw_data[i][2] + " " + raw_data[i][1]);
        twitter_data[i].setEmail(raw_data[i][3]);
        twitter_data[i].setNumTweets(stoi(raw_data[i][4]));
        twitter_data[i].setCategory(raw_data[i][5]);
    }

    // Your code goes here

    // MAP SCENARIO 1: Search based on UserName //

    // Create a new map
    map<string, TwitterData> map_Scenario1;
   // const string username;

    // Insertion  of all the Twitter data into the map
    for (int i = 0; i < 5; i++) {
        map_Scenario1.insert(make_pair(twitter_data[i].getUserName(), twitter_data[i]));
    }

    // Iterate through the map and print the key-value pairs line by line
    cout << "Print Search based on UserName map" << endl;
    for (auto x: map_Scenario1) {

        // Username; username, actual name, email, numTweet, category

        // Print all usernames as key

        cout << "Key: " << x.first << " Value: " << x.second.getUserName() << ", ";
        cout << x.second.getActualName() << ", " << x.second.getEmail() << ", ";
        cout << x.second.getNumTweets() << ", " << x.second.getCategory()  << endl;
    }

     //Find the person whose username is savage1 and print out the entire record of that person

    for (auto x: map_Scenario1) {
        if (x.second.getUserName() == "savage1") {
            cout << "Search for key: savage1 " << "Value: ";
            cout << x.second.getUserName() << ", ";
            cout << x.second.getActualName() << ", " << x.second.getEmail() << ", ";
            cout << x.second.getNumTweets() << ", " << x.second.getCategory() << endl;
        }
    }

    // Remove savage 1

    map<string,TwitterData>::iterator z;
    z = map_Scenario1.find("savage1");

    if (z != map_Scenario1.end())
    {
        map_Scenario1.erase((*z).first);
        cout << "Savage1 has been removed from the map!" << endl;
    }

    else
    {
        cout << "Savage1 has not been found in the map" << endl;
    }


    //map_Scenario1.erase("savage1");

    /////                              ///////
    //  MAP SCENARIO 2 : Search based on EmailAddress //
    ////////                               ///////

        // Create a new map
    map<string, TwitterData> map_Scenario2;
    const string username;

    // Insertion  of all the Twitter data into the map
    for(int i = 0; i < 5; i++)
    {
        map_Scenario2.insert(make_pair(twitter_data[i].getEmail(), twitter_data[i]));
    }

    // Iterate through the map and print the key-value pairs line by line

    cout << "Print Search based on email map" << endl;
    for(auto x: map_Scenario2)
    {

        cout << "Key: " << x.first << " Value: " << x.second.getUserName() << ", ";
        cout << x.second.getActualName() << ", " << x.second.getEmail() << ", ";
        cout << x.second.getNumTweets() << ", " << x.second.getCategory()  << endl;
    }

          // Finding the person with kat@gmail.com as email and print the entire record

    for(auto x: map_Scenario2)
    {
        if(x.second.getEmail() == "kat@gmail.com")
        {
            cout << "Search for key: kat@gmail.com " << "Value: ";
            cout  << x.second.getUserName() << ", ";
            cout << x.second.getActualName() << ", " << x.second.getEmail() << ", ";
            cout << x.second.getNumTweets() << ", " << x.second.getCategory()  << endl;
        }
    }


    // Remove person that has from the map

       map<string,TwitterData>::iterator y;
        y = map_Scenario2.find("kat@gmail.com");

        if (y != map_Scenario2.end())
        {
            map_Scenario2.erase((*y).first);
            cout << "Kat has been removed from the map!" << endl;
        }

        else
        {
            cout << "Kat has not been found in the map" << endl;
        }


    return 0;
}
