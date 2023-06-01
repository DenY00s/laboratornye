#include <iostream>
#include <string>

class FibbonachiShiffer
{
private:
    std::string m_Message;
    std::string m_Words[30];
    int m_FiboKey[30] = { 1, 2 };
    int m_CurrentKey[30] = {};
    int m_WordCount = 1;

    void FibbonachiSequence()
    {
        for (int i = 2; i < m_WordCount; i++)
        {
            m_FiboKey[i] = m_FiboKey[i - 1] + m_FiboKey[i - 2];
        }
    }

    void WordsCount(const std::string& Message)
    {
        for (int i = 0; i < Message.length(); i++)
        {
            if (Message[i] == ' ')
            {
                m_WordCount++;
            }
        }
        if (m_WordCount > 30)
        {
            throw "Too many words!";
        }
    }

public:
    FibbonachiShiffer(std::string Message)
    {
        m_Message = Message;
        WordsCount(Message);
        FibbonachiSequence();
        int counter = -1;
        for (int i = 0; i < m_WordCount; i++)
        {
            counter++;
            while (Message[counter] != ' ')
            {
                if (counter >= Message.length())
                {
                    break;
                }
                m_Words[i] += Message[counter];
                counter++;
            }
        }
    }

    ~FibbonachiShiffer()
    {
        std::cout << "End_OF_PROGRAMME";
    }

    void ShowText()
    {
        std::string s = "";
        for (int i = 0; i < m_WordCount; i++)
        {
            s += m_Words[i];
            s += " ";
        }
        std::cout << s << std::endl;
    }

    void InputKey()
    {
        std::cout << "Input Key: ";
        for (int i = 0; i < m_WordCount; i++)
        {
            std::cin >> m_CurrentKey[i];
        }
        isKeyCorrect();
    }

    void Encode()
    {
        std::string Swapwords[30];
        for (int i = 0; i < m_WordCount; i++)
        {
            for (int j = 0; j < m_WordCount; j++)
            {
                if (m_CurrentKey[i] == m_FiboKey[j])
                {
                    Swapwords[i] = m_Words[j];
                }
            }
        }
        for (int i = 0; i < m_WordCount; i++)
        {
            m_Words[i] = Swapwords[i];
        }
    }

    void Decode()
    {
        std::string Swapwords[30];
        for (int i = 0; i < m_WordCount; i++)
        {
            for (int j = 0; j < m_WordCount; j++)
            {
                if (m_CurrentKey[j] == m_FiboKey[i])
                {
                    Swapwords[i] = m_Words[j];
                }
            }
        }
        for (int i = 0; i < m_WordCount; i++)
        {
            m_Words[i] = Swapwords[i];
        }
    }

    void Output()
    {
        std::cout << std::endl;
        for (int i = 0; i < m_WordCount; i++)
        {
            std::cout << m_Words[i] << " ";
        }
        std::cout << std::endl << std::endl;
	}
    void isKeyCorrect()
    {
        int flag = 0;
        for (int i = 0; i < m_WordCount; i++)
        {
            for (int j = 0; j < m_WordCount; j++)
            {
                if (m_CurrentKey[i] == m_FiboKey[j])
                {
                    flag++;
                    break;
                }
            }
        }
        if (flag != m_WordCount)
        {
            throw "Incorrect code!";
        }
    }

    void OutputCurrentKey()
    {
        std::cout << "Current key: ";
        for (int i = 0; i < m_WordCount; i++)
        {
            std::cout << m_CurrentKey[i] << " ";
        }
    }
};

int main()
{
    try
    {
        std::cout << "Input message: ";
        std::string str;
        std::getline(std::cin, str);
        FibbonachiShiffer Mess(str);
        std::cout << std::endl << "Encode: " << std::endl;
        Mess.InputKey();
        Mess.Encode();
        Mess.OutputCurrentKey();
        std::cout << std::endl << "Output: ";
        Mess.Output();
        std::cout << std::endl << "Decode: " << std::endl;
        Mess.InputKey();
        Mess.Decode();
        Mess.OutputCurrentKey();
        std::cout << std::endl << "Output: ";
        Mess.Output();
    }
    catch (const char* message)
    {
        std::cout << message;
    }

    return 0;
}