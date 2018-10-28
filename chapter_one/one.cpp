#include <algorithm>
#include <iostream>
#include <string>
#include <set>
#include <array>
#include <vector>

// reverse c-string way
std::string reverse(std::string word)
{
    int n = word.size() / 2;
    char temp;
    for (auto i = 0; i < n; i++)
    {
        temp = word[i];
        word[i] = word[word.size() -1 - i];
        word[word.size() - 1 - i] = temp;;
    }
    return word;
}

// reverse modern way
std::string modern_reverse(std::string word)
{
    std::reverse(word.begin(), word.end());
    return word;
}

// unique characters in a string
bool chars_are_unique(std::string word)
{
    std::set<char> seen = {};
    for (auto c: word)
    {
        if (seen.count(c))
        {
            return false;
        }
        else
        {
            seen.insert(c);
        }
    }
    return true;
}

// remove dupes - without additional buffer
std::string remove_duplicates(std::string word)
{
    /**
    * if not a dupe -> write it to current tail and increment tail
    * if a dupe -> don't increment tail and continue to next char
    */
    if (word.size() <= 1)
    {
        return word;
    }

    int tail = 0;
    for (int i = 0; i < word.size(); i++)
    {
        bool isDupe = false;
        for (int j = 0; j < i; j++)
        {
            if (word[j] == word[i])
            {
                isDupe = true;
                break;
            }
        }
        if (!isDupe)
        {
            word[tail] = word[i];
            tail++;
        }
    }
    word = word.substr(0, tail);
    return word;
}


std::string remove_duplicates_modern(std::string word)
{
    std::set<char> seen = {};
    auto f = [&seen](char c)
        {
            if (seen.count(c))
            {
                return true;
            }
            else
            {
                seen.insert(c);
                return false;
            }
        };
    auto it = std::remove_if(
        std::begin(word),
        std::end(word),
        [seen](char c) mutable
        {
            if (seen.count(c))
            {
                return true;
            }
            else
            {
                seen.insert(c);
                return false;
            }
        }
   );
}


bool is_anagram(std::string word_a, std::string word_b)
{
    /**
     * use hash and count occurrences then compare maps (3N)
     * ascii vector, 0 to 256 (3N)
     */
    std::array<int, 256> a = {0};
    std::array<int, 256> b = {0};

    for (auto c: word_a)
    {
        a[int(c)]++;
    }
    for (auto c: word_b)
    {
        b[int(c)]++;
    }
    return a == b;
}


void copy_if_example()
{
    std::vector<int> a = {};
    std::vector<int> b = {1,2,3,4,5,6,7,8};
    auto is_even_func = [](int num) { return num % 2 == 0; };
    auto blah = std::copy_if(std::begin(b), std::end(b), std::back_inserter(a), is_even_func);

    for (int n: a)
    {
        std::cout << n << std::endl;
    }
}


int main(int argc, char const *argv[])
{
    std::string word_a = "bjjjjjjjjjjjjjjjjjjjjjjjjjjjjta";
    std::string word_b = "jjjjjjjjjjjjjjjjjjjbjjjjjjjjjt";

    std::cout << word_a << std::endl;
    std::cout << word_b << std::endl;
    if (is_anagram(word_a, word_b))
    {
        std::cout << "IS anagram" << std::endl;
    }
    else
    {
        std::cout << "NOT anagram" << std::endl;
    }
    return 0;
}
