# FAQ Matching System in C

## Overview

This is a simple **FAQ matching program written in C**. It allows users to ask common questions and automatically provides answers from a predefined set of FAQs. The program is designed for **hackathon scenarios or small shop/customer service applications**.

The program performs **basic keyword matching** and is **case-insensitive**, returning the most relevant answer or a default message if no match is found.

---

## Features

- Supports up to **5 FAQs** (adjustable via `MAX_FAQS`).  
- **Case-insensitive matching** for user questions.  
- Matches based on **keywords** in the question.  
- Returns a default message if no match is found:  
  > "Sorry, please contact the shop."  
- Written entirely in **standard C** using `stdio.h`, `string.h`, and `ctype.h`.  

---

## How It Works

1. **Normalization**  
   Converts all text to lowercase for case-insensitive comparison.  

2. **Keyword Matching**  
   - Splits the user’s question into individual words.  
   - Compares each word with each FAQ question.  
   - Counts matching words to calculate a score.  

3. **Answer Selection**  
   - Returns the answer with the **highest keyword match score**.  
   - If no match is found, returns a default polite response.  

---

## Example Usage

### Run the Program

```bash
gcc faq_matching.c -o faq_matching
./faq_matching
