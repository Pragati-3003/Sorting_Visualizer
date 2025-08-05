<!-- Sorting Algorithm Visualizer -->

<h1 align="center">Sorting Algorithm Visualizer</h1>

<p align="center">
  A real-time C-based sorting algorithm visualizer using SDL2 graphics library.<br/>
  Observe how sorting algorithms work through animated, color-coded bars that visually represent the sorting steps.
</p>

---

## 🚀 Features

- 🎯 **6 Sorting Algorithms**: Selection Sort, Bubble Sort, Insertion Sort, Quick Sort, Heap Sort, Merge Sort  
- 📊 **Real-time Visualization**: Animated bars show each sorting step  
- 🎨 **Color Coding**:
  - 🔴 Red: Current element
  - 🟢 Green: Elements being compared
  - ⚪ White: Idle elements
- 🎮 **Interactive Controls**: Use keys to switch algorithms or reset  
- 🧠 **Educational Tool**: Understand time complexities visually  
- 🧩 **Cross-platform**: Built using SDL2 for Windows, Linux, and macOS

---

## 🎥 Demo

▶️ [Watch Demo Video](https://drive.google.com/file/d/1DqZNHtaHiXKhWgLlzPloOBe_3NsuV_xJ/view?usp=drive_link)

---

## 🛠️ Technologies Used

- **Language**: C  
- **Graphics**: SDL2 (Simple DirectMedia Layer)  
- **Text Rendering**: SDL2_TTF  
- **Build System**: Makefile / GCC

---

## 📦 Getting Started

1. **Clone the repository:**
   ```bash
   git clone https://github.com/Pragati-3003/Sorting_Visualizer.git
   cd Sorting_Visualizer


2. **Build the project:**

   **Option A: Using Makefile**
   ```bash
   make
   ```

   **Option B: Manual Compilation**
   ```bash
   gcc -o sorting.exe sorting.c -Isrc/include -Lsrc/lib -lSDL2 -lSDL2_ttf -lSDL2main
   ```

3. **Run the application:**
   ```bash
   ./sorting.exe
   ```
   Or double-click on `sorting.exe` file (Windows)

---

## 🎮 Controls

| Key   | Action                  | Description                               |
|-------|-------------------------|-------------------------------------------|
| `1`   | Selection Sort          | O(n²) selection-based algorithm            |
| `2`   | Bubble Sort             | O(n²) adjacent swaps                       |
| `3`   | Insertion Sort          | O(n²) incremental sorted insertion         |
| `4`   | Quick Sort              | O(n log n) pivot partitioning              |
| `5`   | Heap Sort               | O(n log n) heap-based sorting              |
| `6`   | Merge Sort              | O(n log n) recursive merge strategy        |
| `R`   | Reset                   | Generate new random dataset                |
| `ESC` | Exit                    | Close the application                      |

---

## 📁 Project Structure

```
Sorting_Visualizer/
├── sorting.c             # Main source file
├── sorting.exe           # Compiled executable
├── makefile              # Build configuration
├── README.md             # Project documentation
├── INTERVIEW_QA.md       # Interview preparation Q&A
├── *.ttf                 # Font files for SDL2_TTF
├── *.dll                 # SDL2 runtime DLLs
├── include/              # SDL2 headers
│   └── SDL2/
├── lib/                  # SDL2 libraries
├── src/
│   ├── include/
│   └── lib/
└── source/               # Additional source files
```

---

## 🤝 Contributing

Feel free to contribute to the project. Fork the repository, create a new branch, and submit a pull request with your enhancements.

---

## 📝 License

This project is licensed under the MIT License © 2024 Pragati Jain.
