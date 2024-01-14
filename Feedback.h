#include<iostream>
#include<string>
#include<time.h>
#include<fstream>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#define size 5
using namespace std;

class Feedback {
public:
    string gArray[size] = {
        "Thank you for your positive feedback!",
        "Thank you for your kind words! We're delighted to hear that you had a great experience with our software application.",
        "Your positive feedback made our day! We're here to provide the best service possible, and it's great to know we're on the right track.",
        "Your positive feedback inspires us to continue delivering excellence. We're committed to maintaining the high standards you've come to expect.",
        "Customer satisfaction is our primary goal, and your positive feedback is a testament to our efforts. Thank you for your trust."
    };

    string bArray[size] = {
        "Thank you for sharing your feedback. We're truly sorry to hear about the issues you encountered while using our software.",
        "We apologize for the inconvenience you experienced with our software. Your feedback is valuable to us.",
        "I'm sorry to hear that you had a negative experience with our software. We take your concerns seriously. We are committed to delivering a better experience, and your feedback helps us identify areas for improvement.",
        "It's disappointing to learn that our software did not meet your expectations. We're committed to resolving these issues promptly.",
        "We understand the frustration you've experienced, and we are determined to make your next interaction with our software a better one."
    };

    string mArray[size] = {
        "Your comments provide valuable insights for us to work on enhancing your future experiences with our software.",
        "We're committed to continuous improvement, and your feedback serves as a stepping stone toward achieving that goal. Thank you for sharing your thoughts.",
        "Thank you for taking the time to share your thoughts. We are actively working on implementing changes based on your feedback to improve your experience.",
        "Your feedback is an essential part of our ongoing efforts to improve. We'll use your insights to refine and enhance our service.",
        "Your medium-level feedback is helping us identify areas for refinement, and we're dedicated to taking the necessary steps to make things right."
    };

    Feedback() {
    }

    int getRandomNumber() {
        srand(time(0));
        int randomNumber = 0 + rand() % 5;
        return randomNumber;
    }

    void FeedbackInput() {
    	system("Color 0D"); 
        string word;
        cout << "\nEnter feedback: ";
        cin >> word;
        for (int i ; i<word.length() ;i++) 
	{
		word[i] = tolower(word[i]);
	}
        if (word == "outstanding" || word == "impressive" || word == "exceptional" || word == "excellent" || word == "superb" || word == "user-friendly" || word == "marvellous" || word == "innovative" || word == "easy-to-use" || word == "very well-designed") {
            int c = getRandomNumber();
            cout << gArray[c];
        }
        else if (word == "streamlined" || word == "efficient" || word == "responsive" || word == "fast" || word == "reliable" || word == "secure" || word == "user-centric" || word == "mobile-friendly" || word == "well-designed") {
            int c = getRandomNumber();
            cout << mArray[c];
        }
        else if (word == "glitchy" || word == "buggy" || word == "unreliable" || word == "slow" || word == "inefficient" || word == "incompatible" || word == "confusing" || word == "frustrating" || word == "non-responsive" || word == "poorly designed") {
            int c = getRandomNumber();
            cout << bArray[c];
        }
        else {
            cout << "\nThank you for your feedback.";
        }
    }
};