// regexSearchEmail.cpp

#include <iostream>
#include <regex>
#include <string>

int main()
{

    std::cout << std::endl;

    std::string emailText = "A text with an email address: rainer@grimm-jaud.de.";

    // (1)
    std::string regExprStr(R"(([\w.%+-]+)@([\w.-]+\.[a-zA-Z]{2,4}))");
    std::regex rgx(regExprStr);

    // (2)
    std::smatch smatch;

    if (std::regex_search(emailText, smatch, rgx)) {

        // (3)

        std::cout << "Text: " << emailText << std::endl;
        std::cout << std::endl;
        std::cout << "Before the email address: " << smatch.prefix() << std::endl;
        std::cout << "After the email address: " << smatch.suffix() << std::endl;
        std::cout << std::endl;
        std::cout << "Length of email adress: " << smatch.length() << std::endl;
        std::cout << std::endl;
        std::cout << "Email address: " << smatch[0] << std::endl;
        std::cout << "Local part: " << smatch[1] << std::endl;
        std::cout << "Domain name: " << smatch[2] << std::endl;
    }

    std::cout << std::endl;
}
