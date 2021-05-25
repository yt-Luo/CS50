#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // check if name matches one of the names of the candidates.
    for (int i = 0; i < candidate_count; i++)
    {
        if (name == candidates[i].name)
        {
            // update that candidate’s vote and return true.
            candidates[i].votes++;
            return true;
        }
    }
    // name does not match the name of any of the candidates. return false
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int winvote = 0;
    string winner;
    // find maximum number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > winvote)
        {
            winvote = candidates[i].votes;
            winner = candidates[i].name;
        }
    }
    //  print out the name of the candidate who received the most votes in the election, and then print a newline.
    printf("%s\n", winner);
    //  check if multiple candidates each have the maximum number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == winvote)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}

