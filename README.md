# Code with C — C Programming Learning Lab

A modern, multilingual web platform to **learn, practice, solve and build** with C programming — featuring 32 hand-written C programs with explanations and sample output, a practice problem set, and curated interview questions.

<p align="center">
  <a href="https://priyajitpaul4-cmyk.github.io/Code-with-C/">
    <img src="https://img.shields.io/badge/🔗_Live_Demo-View_Site-7c3cff?style=for-the-badge" alt="Live Demo" />
  </a>
</p>

---

## ✨ Features

- **32 C Programs** — categorized from basics to intermediate DSA (arrays, recursion, searching, backtracking, greedy, DP, and more), each with source code, a plain-English explanation, and sample output
- **Sample Problems** — a curated practice set with difficulty tags, author, likes and comments
- **Interview Questions** — an expandable Q&A section covering core C concepts
- **Search & Filter** — instantly search programs by name, category, or number
- **Multilingual UI** — supports English, Bengali, Hindi, Spanish, French and German
- **Light / Dark Theme** — theme preference saved across visits
- **Responsive Design** — works cleanly across desktop and mobile
- **Zero Backend** — fully static site, driven by JSON data files

## 🛠️ Tech Stack

| Layer     | Technology                         |
|-----------|-------------------------------------|
| Structure | HTML5                                |
| Styling   | CSS3 (custom properties, responsive) |
| Behavior  | Vanilla JavaScript (no frameworks)   |
| Data      | Static JSON files                    |
| Programs  | C (C99)                              |

## 📁 Project Structure

```
Code-with-C/
│
├── index.html                     # Main site markup
├── style.css                      # Styling and theming
├── script.js                      # App logic (rendering, search, i18n)
├── data.json                      # All 32 programs: code, explanation, output
│
├── C Programming/                 # Original, compilable C source
│   ├── 01_number_base_conversion.c
│   ├── 02_largest_smallest_of_three.c
│   ├── ...
│   ├── 32_climbing_stairs_dp.c
│   ├── main.c                     # Menu-driven entry point
│   └── projects.h                 # Function prototypes
│
├── Problems/
│   └── sample-problems.json       # Practice problem set
│
├── Interview/
│   └── interview-questions.json   # Interview Q&A
│
└── assets/
    ├── images/
    └── icons/
```

## 🚀 Getting Started

### Run the website locally

```bash
git clone https://github.com/priyajitpaul4-cmyk/Code-with-C.git
cd Code-with-C
```

Since the site fetches local JSON files, open it through a local server rather than double-clicking `index.html`:

```bash
python3 -m http.server 8000
# then visit http://localhost:8000
```

### Compile and run the C programs

All 32 programs are wired into a single menu-driven CLI via `main.c`:

```bash
cd "C Programming"
gcc -o lab main.c *.c -lm
./lab
```

## 🗂️ Program Categories

| Category | Count |
|---|---|
| Basic Programs | 10 |
| Operators | 3 |
| Functions & Recursion | 4 |
| Numbers | 2 |
| Arrays & Hashing | 3 |
| Strings | 1 |
| Two Pointers & Searching | 3 |
| Heap / Priority Queue | 1 |
| Backtracking | 1 |
| Greedy | 1 |
| Bit Manipulation | 1 |
| Intervals | 1 |
| Dynamic Programming | 1 |

## 🤝 Contributing

Contributions are welcome! To add a new program, problem, or question:

1. Fork the repo and create a new branch
2. Add your `.c` file to `C Programming/` (and register it in `main.c` / `projects.h` if it should appear in the CLI menu)
3. Add a matching entry to `data.json`, `Problems/sample-problems.json`, or `Interview/interview-questions.json`
4. Open a pull request

## 📄 License

This project is open source and available for learning purposes. Feel free to fork and build on it.

## 👤 Author

**Priyajit Paul**
[GitHub](https://github.com/priyajitpaul4-cmyk) · [Live Demo](https://priyajitpaul4-cmyk.github.io/Code-with-C/)

---

<p align="center">Made for learners, by a learner — Code with C 💻</p>
