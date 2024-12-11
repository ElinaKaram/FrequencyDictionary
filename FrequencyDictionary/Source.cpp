#include <iostream>
#include <string>
#include <vector>
using namespace std;


string cleanWord(const string& word) 
{
    string cleaned;
    for (char ch : word)
    {
        if (isalpha(ch)) 
        {
            cleaned += tolower(ch);
        }
    }
    return cleaned;
}

int main() 
{
    vector<string> inputText = 
    {
        "Hello", "world", "this", "is", "test", "hello", "universe", "test", "world"
    };

    vector<pair<string, int>> wordFrequency;

    for (const auto& word : inputText)
    {
        string cleanedWord = cleanWord(word);
        if (!cleanedWord.empty())
        {
            bool found = false;

            for (auto& pair : wordFrequency) 
            {
                if (pair.first == cleanedWord)
                {
                    pair.second++;
                    found = true;
                    break;
                }
            }
            if (!found) 
            {
                wordFrequency.push_back(make_pair(cleanedWord, 1));
            }
        }
    }

    cout << "Word frequency:" << endl;
    for (const auto& pair : wordFrequency) 
    {
        cout << pair.first << ": " << pair.second << endl;
    }

    pair<string, int> mostFrequent = { "", 0 };
    for (const auto& pair : wordFrequency)
    {
        if (pair.second > mostFrequent.second) 
        {
            mostFrequent = pair;
        }
    }
    cout << "Most frequent word: " << mostFrequent.first << " (" << mostFrequent.second << " times)" << endl;

    return 0;
}
