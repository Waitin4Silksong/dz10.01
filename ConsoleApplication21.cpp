#include <iostream>
#include <string>
#pragma warning(disable : 4996) // disabling all strcpy warnings

class String
{
private:
    char* line;
public:
    // 1.
    String() : line(nullptr) {}
    // 2.
    String(const char* line_)
    {
        delete[] line;
        if (line_ != nullptr)
        {
            line = new char[strlen(line_) + 1];
            strcpy(line, line_);
        }
        else
        {
            line = nullptr;
        }
    }
    // 3.
    String(const String& copy)
    {
        if (copy.line != nullptr)
        {
            line = new char[strlen(copy.line) + 1];
            strcpy(line, copy.line);
        }
        else
        {
            line = nullptr;
        }
    }
    // destructor
    ~String()
    {
        delete[] line;
    }
    // 4. line
    void replace(const char* line_)
    {
        if (line_ != nullptr)
        {
            line = new char[strlen(line_) + 1];
            strcpy(line, line_);
        }
        else
        {
            line != nullptr;
        }
    }
    // 4. string
    void replace(const String& line_)
    {
        if (line_.line != nullptr)
        {
            line = new char[strlen(line_.line) + 1];
            strcpy(line, line_.line);
        }
        else
        {
            line != nullptr;
        }
    }
    // 5.
    String returning(int start, int end) const
    {
        if (start >= 0 && start <= strlen(line) && end >= 0 && end <= strlen(line))
        {
            char* returnLine = new char[end - start + 2];
            strncpy(returnLine, line + start, end - start + 1);
            returnLine[end - start + 1] = '\0';
            return returnLine;
        }
        else
        {
            std::cout << "Invalid range";
        }
    }
    // 6.
    void print()
    {
        std::cout << line;
    }
    // 7.
    // tbh i used GPT to do it. I don't really know is this a right method.
    int amount() const
    {
        int count = 0;
        const char* word = line;
        while (*word != '\0')
        {
            while (*word != '\0' && *word == ' ')
            {
                word++;
            }
            if (*word != '\0')
            {
                count++;
            }
            while (*word != '\0' && *word != ' ')
            {
                word++;
            }
        }
        return count;
    }
};

int main()
{
    String str1("Hello Hi World");
    String str2("Hello Hello");
    str1.print();
    std::cout << std::endl;
    str2.print();
    std::cout << std::endl;
    str2.replace("Hello World");
    str2.print();
    std::cout << std::endl;
    String num = str1.returning(0, 7);
    num.print();
    std::cout << std::endl;
    std::cout << str1.amount();
}

