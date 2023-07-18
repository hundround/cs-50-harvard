#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int punctuations[] = {'.', '?', '!'}; // Sentences should end to one of these punctuations
int entry_counter(string sentences);
int CL_index(int l, int w, int s);

int main(void)
{
    // Have the user input sentence(s)
    string main_sentence = get_string("Text: ");

    // Print the grade level
    int n = entry_counter(main_sentence);
    if (n < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (n > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", entry_counter(main_sentence));
    }
}

string uppercase_entry(string sentences) // Make the sentence in uppercase to have one range (in this case, 65-90) of values
{
    for (int i = 0, n = strlen(sentences); i < n; i++)
    {
        sentences[i] = toupper(sentences[i]);
    }
    return sentences;
}

int CL_index(int l, int w, int s) // Coleman-Liau Index
{
    float L = l * 100 / (float) w;
    float S = s * 100 / (float) w;
    float grade = (0.0588 * L) - (0.296 * S) - 15.8;
    return round(grade);
}

int entry_counter(string sentences) // Main counter of letters, words, and sentences
{
    int l = 0, w =  1, s = 0;
    string main_sentences = uppercase_entry(sentences);
    for (int i = 0, n = strlen(main_sentences); i < n; i++)
    {
        if (main_sentences[i] >= 'A' && main_sentences[i] <= 'Z') // Letter count
        {
            l++;
        }
        else if (main_sentences[i] == ' ') // Word count
        {
            w++;
        }
        else
        {
            for (int j = 0; j < 3; j++)
            {
                if (main_sentences[i] == punctuations[j]) // Sentence count
                {
                    s++;
                }
            }
        }
    }
    return CL_index(l, w, s);
}