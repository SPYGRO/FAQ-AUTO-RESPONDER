#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT 256
#define MAX_FAQS 5

typedef struct {
    char question[MAX_TEXT];
    char answer[MAX_TEXT];
} FAQ;

void normalize(char text[]) {
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = tolower(text[i]);
    }
}

int match_score(char user_question[], char faq_question[]) {
    int score = 0;
    char temp[MAX_TEXT];

    strcpy(temp, user_question);  // Copy string (important!)
    
    char *word = strtok(temp, " ");
    while (word != NULL) {
        if (strstr(faq_question, word) != NULL) {
            score++;
        }
        word = strtok(NULL, " ");
    }

    return score;
}

char* find_answer(char user_question[], FAQ faqs[], int faq_count) {
    int best_score = 0;
    int best_index = -1;

    normalize(user_question);

    for (int i = 0; i < faq_count; i++) {
        char faq_q[MAX_TEXT];
        strcpy(faq_q, faqs[i].question);
        normalize(faq_q);

        int score = match_score(user_question, faq_q);

        if (score > best_score) {
            best_score = score;
            best_index = i;
        }
    }

    if (best_index == -1) {
        return "Sorry, please contact the shop.";
    }

    return faqs[best_index].answer;
}

int main() {
    FAQ faqs[MAX_FAQS];

    strcpy(faqs[0].question, "what are your hours");
    strcpy(faqs[0].answer, "We are open from 9am to 6pm.");

    strcpy(faqs[1].question, "do you have parking");
    strcpy(faqs[1].answer, "Yes, free parking is available.");

    strcpy(faqs[2].question, "how much is a haircut");
    strcpy(faqs[2].answer, "Haircuts start at $20.");

    int faq_count = 3;

    char user_question[MAX_TEXT];

    printf("Ask a question: ");
    fgets(user_question, MAX_TEXT, stdin);

    printf("\nAnswer: %s\n", find_answer(user_question, faqs, faq_count));

    return 0;
}

