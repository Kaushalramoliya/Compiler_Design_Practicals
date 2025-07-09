# 📚 Compiler Design Laboratory Practicals

**Author:** Ramoliya Kaushal  

---

## 🧠 What is Compiler Design?

Compiler Design focuses on creating software that transforms source code written in one programming language into another. It involves various stages such as lexical analysis, parsing, semantic analysis, code optimization, and code generation.

---

## 🔧 Technologies Used

| Technology     | Purpose                                      |
|----------------|----------------------------------------------|
| C Language     | Writing core programs and logic              |
| LEX / Flex     | Token generation and lexical analysis        |
| YACC / Bison   | Syntax analysis using grammar rules          |
| GCC Compiler   | Compiling generated C source code            |

---

## 🖥️ Software Requirements

- GCC (GNU Compiler Collection)  
- Flex (Fast Lexical Analyzer Generator)  
- Bison/YACC (Yet Another Compiler Compiler)  
- Windows with WSL or MinGW  
- Code editor (e.g., VS Code)

---

## 📖 Definitions

- **Compiler:** A program that translates high‑level source code into target code (machine code or intermediate code).  
- **Lexical Analyzer (Lexer):** First phase of a compiler; reads input characters and groups them into tokens.  
- **Syntax Analyzer (Parser):** Second phase; takes tokens from the lexer and builds a parse tree according to grammar rules.  
- **LEX/Flex:** Tools to generate lexical analyzers automatically from regular‑expression specifications.  
- **YACC/Bison:** Tools to generate parsers from context‑free grammar specifications.  
- **Recursive Descent Parser:** A hand‑written parser built from mutually recursive functions, each implementing a grammar rule.

---

## 📑 Table of Contents

- [Lab 1: Finite Automata in C](#lab-1-finite-automata-in-c)  
- [Lab 2: Hand‑Written Lexical Analyzer in C](#lab-2-hand-written-lexical-analyzer-in-c)  
- [Lab 3: LEX & Flex Overview](#lab-3-lex--flex-overview)  
- [Lab 4: Lex Programs](#lab-4-lex-programs)  
- [Lab 5: Advanced Lexical Analysis](#lab-5-advanced-lexical-analysis)  
- [Lab 6: Recursive Descent Parser](#lab-6-recursive-descent-parser)  
- [Lab 7: YACC + LEX Exercises](#lab-7-yacc--lex-exercises)

---

## Lab 1: Finite Automata in C

**Aim:**  
Implement various finite‑automata based recognizers for patterns such as “starts with a”, “ends with a”, “ends with ab”, and “contains ab” over the alphabet {a, b}.  

**Files:**  
- `Lab-1/a_startwitha.c`  
- `Lab-1/b_endswitha.c`  
- `Lab-1/c_endswithab.c`  
- `Lab-1/d_containsab.c`  

---

## Lab 2: Hand‑Written Lexical Analyzer in C

**Aim:**  
Build a custom lexical analyzer in C to identify tokens including identifiers, keywords, operators, numbers, and comments without using LEX/Flex.  

**Files:**  
- `Lab-2/identifier.c`  
- `Lab-2/operator.c`  
- `Lab-2/number.c`  
- `Lab-2/comments.c`  
- `Lab-2/lexer.c`  

---

## Lab 3: LEX & Flex Overview

**Aim:**  
Study the structure of a Flex specification file (`.l`), including declarations, rules, and actions; observe common token‑matching patterns.  

**Contents:**  
- Theory notes  
- Example `.l` files in `Lab-3/` directory  

---

## Lab 4: Lex Programs

**Aim:**  
Write Flex programs for text processing tasks such as counting words, vowels vs consonants, extracting numbers, adding line numbers, and parsing HTML tags/comments.  

**Files:**  
- `Lab-4/count_words.l`  
- `Lab-4/count_vowels_consonants.l`  
- `Lab-4/print_numbers.l`  
- `Lab-4/line_numbers.l`  
- `Lab-4/html_tags.l`  

---

## Lab 5: Advanced Lexical Analysis

**Aim:**  
Extend lexical analysis to handle removal of comments, advanced tokenization of multi‑character operators, literals, and error reporting.  

**Files:**  
- `Lab-5/remove_comments.l`  
- `Lab-5/tokenizer.l`  

---

## Lab 6: Recursive Descent Parser

**Aim:**  
Implement a hand‑coded recursive‑descent parser in C for a simple expression grammar, demonstrating parsing functions corresponding to grammar productions.  

**File:**  
- `Lab-6/recursive_descent.c`  

---

## Lab 7: YACC + LEX Exercises

**Aim:**  
Combine Flex and YACC to build small compilers/parsers, including an arithmetic calculator, infix‑to‑postfix converter, and expression evaluator.  

**Files:**  
- `Lab-7/lexer.l`  
- `Lab-7/parser.y`  

---

> ✨ **All source files** (`.c`, `.l`, `.y`) are organized in their respective `Lab-X/` folders.  
>  
> 🔧 **Build Instructions** (use from each lab’s directory):  
> ```bash
> flex <prog>.l
> yacc -d <parser>.y  # only for YACC labs
> gcc lex.yy.c y.tab.c -lfl -o <output_executable>
> ./<output_executable> <input_file>
> ```  

---

## 🎯 Learning Outcomes

By completing this lab, students will:

- ✅ Understand the working of compilers, from **lexical analysis** to **parsing**
- ✅ Develop **custom compilers** for evaluating basic arithmetic and language expressions
- ✅ Use **LEX and YACC** tools to automate token generation and grammar parsing
- ✅ Analyze **context-free grammars (CFGs)** and write parsers both manually and using tools
- ✅ Work confidently with **Linux-based command-line tools**, compilers, and debugging utilities

---

## 🙋 About Me

> 👨‍💻 **Kaushal Ramoliya**  
> 🎓 B.Tech in Computer Science & Engineering  
> 📧 Email: [kaushalramoliya17@gmail.com](mailto:kaushalramoliya17@gmail.com)  
> 🌐 LinkedIn: [linkedin.com/in/kaushalramoliya](https://www.linkedin.com/in/kaushalramoliya)  
> 💻 GitHub: [github.com/kaushalramoliya](https://github.com/Kaushalramoliya) 
