#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define NUM_BARS 50
#define BAR_WIDTH (WINDOW_WIDTH / NUM_BARS) - 5
#define DELAY 50
void selectionSort(SDL_Renderer *renderer, int *bars);
void bubbleSort(SDL_Renderer *renderer, int *bars);
void insertionSort(SDL_Renderer *renderer, int *bars);
void drawBars(SDL_Renderer *renderer, int *bars, int current, int compareIndex);
void generateRandomBars(int *bars);
void renderText(SDL_Renderer *renderer, TTF_Font *font, const char *text, int x, int y, SDL_Color color);

void drawBars(SDL_Renderer *renderer, int *bars, int current, int compareIndex)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (int i = 0; i < NUM_BARS; i++)
    {
        if (i == current)
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        else if (i == compareIndex)
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        else
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        int barHeight = bars[i];
        if (barHeight < 1)
        {
            barHeight = 1;
        }
        else if (barHeight > WINDOW_HEIGHT - 50)
        {
            barHeight = WINDOW_HEIGHT - 50;
        }

        SDL_Rect bar = {i * (BAR_WIDTH + 5), WINDOW_HEIGHT - barHeight, BAR_WIDTH, barHeight};
        SDL_RenderFillRect(renderer, &bar);
    }

    SDL_RenderPresent(renderer);
}

void renderText(SDL_Renderer *renderer, TTF_Font *font, const char *text, int x, int y, SDL_Color color)
{
    SDL_Surface *surface = TTF_RenderText_Solid(font, text, color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_Rect destRect = {x, y, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &destRect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

// Selection sort algorithm
void selectionSort(SDL_Renderer *renderer, int *bars)
{
    for (int i = 0; i < NUM_BARS - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < NUM_BARS; j++)
        {
            if (bars[j] < bars[minIndex])
            {
                minIndex = j;
            }
            drawBars(renderer, bars, j, minIndex);
            SDL_Delay(DELAY);
        }
        int temp = bars[i];
        bars[i] = bars[minIndex];
        bars[minIndex] = temp;
    }
}

// Bubble sort algorithm
void bubbleSort(SDL_Renderer *renderer, int *bars)
{
    for (int i = 0; i < NUM_BARS - 1; i++)
    {
        for (int j = 0; j < NUM_BARS - i - 1; j++)
        {
            if (bars[j] > bars[j + 1])
            {
                int temp = bars[j];
                bars[j] = bars[j + 1];
                bars[j + 1] = temp;
            }
            drawBars(renderer, bars, j, j + 1);
            SDL_Delay(DELAY);
        }
    }
}

// Insertion sort algorithm
void insertionSort(SDL_Renderer *renderer, int *bars)
{
    for (int i = 1; i < NUM_BARS; i++)
    {
        int key = bars[i];
        int j = i - 1;
        while (j >= 0 && bars[j] > key)
        {
            bars[j + 1] = bars[j];
            drawBars(renderer, bars, i, j);
            SDL_Delay(DELAY);
            j = j - 1;
        }
        bars[j + 1] = key;
    }
}

// Function to generate random bars
void generateRandomBars(int *bars)
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < NUM_BARS; i++)
    {
        bars[i] = rand() % WINDOW_HEIGHT;
    }
}

// Quick sort partition function
int partition(SDL_Renderer *renderer, int *bars, int low, int high)
{
    int pivot = bars[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (bars[j] < pivot)
        {
            i++;
            int temp = bars[i];
            bars[i] = bars[j];
            bars[j] = temp;

            drawBars(renderer, bars, i, j);
            SDL_Delay(DELAY);
        }
    }
    int temp = bars[i + 1];
    bars[i + 1] = bars[high];
    bars[high] = temp;

    drawBars(renderer, bars, i + 1, high);
    SDL_Delay(DELAY);

    return i + 1;
}

// Quick sort algorithm
void quickSort(SDL_Renderer *renderer, int *bars, int low, int high)
{
    if (low < high)
    {
        int pi = partition(renderer, bars, low, high);
        quickSort(renderer, bars, low, pi - 1);
        quickSort(renderer, bars, pi + 1, high);
    }
}

// Heapify function
void heapify(SDL_Renderer *renderer, int *bars, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && bars[left] > bars[largest])
        largest = left;

    if (right < n && bars[right] > bars[largest])
        largest = right;

    if (largest != i)
    {
        int temp = bars[i];
        bars[i] = bars[largest];
        bars[largest] = temp;

        drawBars(renderer, bars, i, largest);
        SDL_Delay(DELAY);

        heapify(renderer, bars, n, largest);
    }
}

// Heap sort algorithm
void heapSort(SDL_Renderer *renderer, int *bars)
{
    int n = NUM_BARS;

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(renderer, bars, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        int temp = bars[0];
        bars[0] = bars[i];
        bars[i] = temp;

        drawBars(renderer, bars, 0, i);
        SDL_Delay(DELAY);

        heapify(renderer, bars, i, 0);
    }
}

// Function to get the maximum value in the array for radix sort
int getMax(int *bars)
{
    int max = bars[0];
    for (int i = 1; i < NUM_BARS; i++)
    {
        if (bars[i] > max)
            max = bars[i];
    }
    return max;
}

// Count sort function for radix sort
void countSort(SDL_Renderer *renderer, int *bars, int exp)
{
    int output[NUM_BARS];
    int count[10] = {0};

    for (int i = 0; i < NUM_BARS; i++)
        count[(bars[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = NUM_BARS - 1; i >= 0; i--)
    {
        output[count[(bars[i] / exp) % 10] - 1] = bars[i];
        count[(bars[i] / exp) % 10]--;
    }

    for (int i = 0; i < NUM_BARS; i++)
    {
        bars[i] = output[i];
        drawBars(renderer, bars, i, -1);
        SDL_Delay(DELAY);
    }
}

// Radix sort algorithm
void radixSort(SDL_Renderer *renderer, int *bars)
{
    int max = getMax(bars);

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countSort(renderer, bars, exp);
    }
}

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    if (TTF_Init() == -1)
    {
        printf("TTF_Init Error: %s\n", TTF_GetError());
        SDL_Quit();
        return 1;
    }

    TTF_Font *font = TTF_OpenFont("Arial.ttf", 18);
    if (!font)
    {
        printf("TTF_OpenFont Error: %s\n", TTF_GetError());
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Sorting Visualizer",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          WINDOW_WIDTH, WINDOW_HEIGHT,
                                          SDL_WINDOW_SHOWN);
    if (!window)
    {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        TTF_CloseFont(font);
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        TTF_CloseFont(font);
        SDL_Quit();
        return 1;
    }

    int bars[NUM_BARS];
    generateRandomBars(bars);

    SDL_Event event;
    int quit = 0;
    int sortAlgorithm = 0;

    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = 1;
            }
            if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_1:
                    sortAlgorithm = 1;
                    break;
                case SDLK_2:
                    sortAlgorithm = 2;
                    break;
                case SDLK_3:
                    sortAlgorithm = 3;
                    break;
                case SDLK_4:
                    sortAlgorithm = 4;
                    break;
                case SDLK_5:
                    sortAlgorithm = 5;
                    break;
                case SDLK_6:
                    sortAlgorithm = 6;
                    break;
                case SDLK_r:
                    generateRandomBars(bars);
                    break;
                case SDLK_ESCAPE:
                    quit = 1;
                    break;
                }
            }
        }

        if (sortAlgorithm == 1)
        {
            selectionSort(renderer, bars);
            sortAlgorithm = 0;
        }
        else if (sortAlgorithm == 2)
        {
            bubbleSort(renderer, bars);
            sortAlgorithm = 0;
        }
        else if (sortAlgorithm == 3)
        {
            insertionSort(renderer, bars);
            sortAlgorithm = 0;
        }
        else if (sortAlgorithm == 4)
        {
            quickSort(renderer, bars, 0, NUM_BARS - 1);
            sortAlgorithm = 0;
        }
        else if (sortAlgorithm == 5)
        {
            heapSort(renderer, bars);
            sortAlgorithm = 0;
        }
        else if (sortAlgorithm == 6)
        {
            radixSort(renderer, bars);
            sortAlgorithm = 0;
        }

        drawBars(renderer, bars, -1, -1);

        SDL_Color textColor = {255, 255, 255, 255};
        renderText(renderer, font, "Press 1 for Selection Sort, 2 for Bubble Sort, 3 for Insertion Sort , 4 for Quick Sort ",
                   10, 10, textColor);
        renderText(renderer, font, "Press 5 for Heap sort, 6 for Radix sort , R to reset, ESC to exit ",
                   10, 30, textColor);
        SDL_RenderPresent(renderer);
        SDL_Delay(50);
    }

    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}
