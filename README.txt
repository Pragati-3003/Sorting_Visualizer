# 🎯 Sorting Algorithm Visualizer

![Sorting Visualizer Demo](https://img.shields.io/badge/Platform-Windows-blue) ![Language](https://img.shields.io/badge/Language-C-brightgreen) ![Graphics](https://img.shields.io/badge/Graphics-SDL2-orange) ![License](https://img.shields.io/badge/License-MIT-yellow)

A real-time visual representation of popular sorting algorithms built in C using SDL2 graphics library. Watch as different sorting algorithms organize data step-by-step with color-coded animations, making abstract computer science concepts concrete and observable.

## 📺 Demo Video

```
🎬 Demo Video Preview
https://drive.google.com/file/d/1DqZNHtaHiXKhWgLlzPloOBe_3NsuV_xJ/view?usp=drive_link
```

**What you'll see in the demo:**
- Real-time visualization of 6 different sorting algorithms
- Color-coded bars (Red: current, Green: comparison, White: others)
- Interactive keyboard controls to switch between algorithms
- Performance differences between O(n²) and O(n log n) algorithms

## 🌟 Features

- **6 Sorting Algorithms**: Selection Sort, Bubble Sort, Insertion Sort, Quick Sort, Heap Sort, and Merge Sort
- **Real-time Visualization**: Watch algorithms sort data with animated bars
- **Color-coded Animation**: 
  - 🔴 **Red**: Current element being processed
  - 🟢 **Green**: Element being compared
  - ⚪ **White**: Other elements
- **Interactive Controls**: Switch between algorithms with keyboard shortcuts
- **Random Data Generation**: Generate new random datasets instantly
- **Educational Tool**: Perfect for learning algorithm behavior and performance
- **Cross-platform**: Built with SDL2 for Windows, Linux, and macOS compatibility



### Installation & Running

1. **Clone the repository**
   ```bash
   git clone https://github.com/Pragati-3003/Sorting_Visualizer.git
   cd Sorting_Visualizer
   ```

2. **Build the project**
   
   **Option A: Using Makefile**
   ```bash
   make
   ```
   
   **Option B: Manual compilation**
   ```bash
   gcc -o sorting.exe sorting.c -Isrc/include -Lsrc/lib -lSDL2 -lSDL2_ttf -lSDL2main
   ```

3. **Run the visualizer**
   ```bash
   .\sorting.exe
   ```
   Or simply double-click `sorting.exe`

`

## 🎮 Controls & Usage

| Key | Action | Algorithm |
|-----|--------|-----------|
| `1` | Execute Selection Sort | O(n²) - Simple selection-based sorting |
| `2` | Execute Bubble Sort | O(n²) - Adjacent element swapping |
| `3` | Execute Insertion Sort | O(n²) - Insert elements in sorted position |
| `4` | Execute Quick Sort | O(n log n) - Divide and conquer approach |
| `5` | Execute Heap Sort | O(n log n) - Binary heap-based sorting |
| `6` | Execute Merge Sort | O(n log n) - Merge sorted subarrays |
| `R` | Reset with new random data | Generate fresh dataset |
| `ESC` | Exit program | Close the application |


## 💻 Technology Stack

### Core Technologies

- **Programming Language**: C
- **Graphics Library**: SDL2 (Simple DirectMedia Layer)
- **Font Rendering**: SDL2_TTF
- **Build System**: Makefile
- **Platform**: Windows (with cross-platform SDL2 base)

### Technical Architecture

```
┌─────────────────────────────────────────┐
│              User Interface             │
│  (Keyboard Input + Visual Instructions) │
└─────────────────┬───────────────────────┘
                  │
┌─────────────────▼───────────────────────┐
│           Event Handler                 │
│    (SDL Event Loop + Key Mapping)      │
└─────────────────┬───────────────────────┘
                  │
┌─────────────────▼───────────────────────┐
│        Algorithm Controller            │
│   (Sorting Algorithm Selection)        │
└─────────────────┬───────────────────────┘
                  │
┌─────────────────▼───────────────────────┐
│       Visualization Engine             │
│  (SDL2 Rendering + Animation)          │
└─────────────────────────────────────────┘
```

## 📊 Implemented Algorithms

### O(n²) Algorithms - Quadratic Time Complexity

#### 1. Selection Sort
- **Time Complexity**: O(n²)
- **Space Complexity**: O(1)
- **Stability**: Not stable
- **Description**: Finds the minimum element and places it at the beginning repeatedly
- **Best Use**: Small datasets, educational purposes

#### 2. Bubble Sort
- **Time Complexity**: O(n²)
- **Space Complexity**: O(1)
- **Stability**: Stable
- **Description**: Repeatedly swaps adjacent elements if they're in wrong order
- **Best Use**: Educational demonstration of basic sorting

#### 3. Insertion Sort
- **Time Complexity**: O(n²)
- **Space Complexity**: O(1)
- **Stability**: Stable
- **Description**: Builds the sorted array one element at a time
- **Best Use**: Small datasets, nearly sorted data

### O(n log n) Algorithms - Linearithmic Time Complexity

#### 4. Quick Sort
- **Time Complexity**: O(n log n) average, O(n²) worst case
- **Space Complexity**: O(log n)
- **Stability**: Not stable
- **Description**: Divide-and-conquer algorithm using pivot partitioning
- **Best Use**: General-purpose sorting, large datasets

#### 5. Heap Sort
- **Time Complexity**: O(n log n)
- **Space Complexity**: O(1)
- **Stability**: Not stable
- **Description**: Uses binary heap data structure to sort elements
- **Best Use**: When consistent O(n log n) performance is needed

#### 6. Merge Sort
- **Time Complexity**: O(n log n)
- **Space Complexity**: O(n)
- **Stability**: Stable
- **Description**: Divide-and-conquer algorithm that merges sorted subarrays
- **Best Use**: When stability is required, linked lists

## 🏗️ Project Structure

```
Sorting_Visualizer/
├── 📄 sorting.c              # Main source file with all algorithms
├── ⚙️ sorting.exe            # Compiled executable
├── 🔧 makefile              # Build configuration
├── 📖 README.md             # Project documentation
├── ❓ INTERVIEW_QA.md        # Interview questions and answers
├── 🔤 *.ttf                 # Arial font files
├── 📚 *.dll                 # SDL2 runtime libraries
├── 📁 include/              # SDL2 header files
│   └── SDL2/
├── 📁 lib/                  # SDL2 static libraries
├── 📁 src/                  # SDL2 development files
│   ├── include/
│   └── lib/
└── 📁 source/               # Additional SDL2 resources
```



## 📝 License

This project is open source and available under the **MIT License**.

```
MIT License

Copyright (c) 2024 Pragati-3003

