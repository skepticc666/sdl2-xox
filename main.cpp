#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include <SDL_ttf.h>

std::string checkWinner(char matrix[3][3], char player1, char palyer2)
{
    if (matrix[0][0] != ' ' && matrix[0][0] == matrix[0][1] && matrix[0][1] == matrix[0][2])
    {
        if (matrix[0][0] == player1)
        {
            return "you win!";
        }
        else
        {
            return "yoyu lose";
        }
    }
    else if (matrix[1][0] != ' ' && matrix[1][0] == matrix[1][1] && matrix[1][1] == matrix[1][2])
    {
        if (matrix[1][0] == player1)
        {
            return "you win!";
        }
        else
        {
            return "yoyu lose";
        }
    }
    else if (matrix[2][0] != ' ' && matrix[2][0] == matrix[2][1] && matrix[2][1] == matrix[2][2])
    {
        if (matrix[2][0] == player1)
        {
            return "you win!";
        }
        else
        {
            return "yoyu lose";
        }
    }
    else if (matrix[0][0] != ' ' && matrix[0][0] == matrix[1][0] && matrix[1][0] == matrix[2][0])
    {
        if (matrix[0][0] == player1)
        {
            return "you win!";
        }
        else
        {
            return "yoyu lose";
        }
    }
    else if (matrix[0][1] != ' ' && matrix[0][1] == matrix[1][1] && matrix[1][1] == matrix[2][1])
    {
        if (matrix[0][1] == player1)
        {
            return "you win!";
        }
        else
        {
            return "yoyu lose";
        }
    }
    else if (matrix[0][2] != ' ' && matrix[0][2] == matrix[1][2] && matrix[1][2] == matrix[2][2])
    {
        if (matrix[0][2] == player1)
        {
            return "you win!";
        }
        else
        {
            return "yoyu lose";
        }
    }
    else if (matrix[0][0] != ' ' && matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
    {
        if (matrix[0][0] == player1)
        {
            return "you win!";
        }
        else
        {
            return "yoyu lose";
        }
    }
    else if (matrix[0][2] != ' ' && matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
    {
        if (matrix[0][2] == player1)
        {
            return "you win!";
        }
        else
        {
            return "yoyu lose";
        }
    }
    else
    {
        return "";
    }
}
    

bool checkTie(char matrix[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (matrix[i][j] == ' ')
            {

                return 0;
            }
        }
    }

    std::cout << "game is tie" << std::endl;
    return 1;
}

int main()
{

    int width = 480;
    int height = 680;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    SDL_Renderer *render = SDL_CreateRenderer(window, -1, 0);
    bool isRunning = true;
    SDL_Event e;

    char matrix[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    // int row, coloumn;
    // std::cout << "enter the row" << std::endl;
    // std::cin >> row;
    // std::cout << "enter the coloumn" << std::endl;
    // std::cin >> coloumn;
    // if(matrix[row][coloumn]==' '){
    //     matrix[row][coloumn] = 'X';
    // }

    // int row1,coloumn1;
    // row1 = rand() % 4;
    // coloumn1 = rand() % 4;
    // if(matrix[row1][coloumn1] == ' '){
    //     matrix[row1][coloumn1] = 'O';
    // }

    bool isMouseDown = false;

    // font
    if (TTF_Init() < 0)
    {
        std::cout << "Error initializing SDL_ttf: " << TTF_GetError() << std::endl;
    }

    TTF_Font *font;
    font = TTF_OpenFont("C:\\sdl2 3\\sample.ttf", 24);
    if (!font)
    {
        std::cout << "Failed to load font: " << TTF_GetError() << std::endl;
    }

    // text initialization begins here
    SDL_Color text_color = {255, 255, 255, 255};
    SDL_Surface *text = TTF_RenderText_Solid(font, "GAME OVER!", text_color);

    SDL_Texture *text_texture = SDL_CreateTextureFromSurface(render, text);
    // text ends begins here

    // text.w;

    SDL_Rect src = {0, 0, text->w, text->h};
    SDL_Rect dest = {width / 2 - text->w * 4 / 2, height / 2 - text->h * 4 / 2, text->w * 4, text->h * 4};

    bool player1 = true;
    bool finished = false;


    while (isRunning)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                isRunning = false;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                isMouseDown = true;
                break;
            }
            isMouseDown = false;
        }

        if(finished == true){
            continue;
        }

        SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
        SDL_RenderClear(render);

        SDL_Rect rect1;
        rect1.x = width / 8;
        rect1.y = height / 7;
        rect1.w = width / 5;
        rect1.h = width / 5;

        int x, y;
        SDL_GetMouseState(&x, &y);

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {

                SDL_SetRenderDrawColor(render, 0, 100, 100, 255);
                SDL_RenderDrawRect(render, &rect1);

                if (x > rect1.x && x < rect1.x + rect1.w)
                {
                    if (y > rect1.y && y < rect1.y + rect1.h)
                    {

                        SDL_SetRenderDrawColor(render, 0, 255, 255, 255);
                        SDL_RenderFillRect(render, &rect1);
                        // if(isMouseDown){
                        //     matrix[i][j] = 'X';
                        // }

                        if (player1)
                        {
                            if (isMouseDown)
                            {
                                if (matrix[i][j] == ' ')
                                {
                                    matrix[i][j] = 'X';
                                    player1 = false;
                                }
                            }
                        }
                        if (!player1)
                        {
                            int row1 = rand() % 3;
                            int col1 = rand() % 3;
                            if (matrix[row1][col1] == ' ')
                            {
                                matrix[row1][col1] = 'O';
                                player1 = true;
                            }
                        }
                        // std::cout << x << " " << y << std::endl;
                    }
                }

                // std::cout << isMouseDown << std::endl;

                if (matrix[i][j] == 'X')
                {
                    SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
                    SDL_RenderFillRect(render, &rect1);
                }
                if (matrix[i][j] == 'O')
                {
                    SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
                    SDL_RenderFillRect(render, &rect1);
                }

                rect1.x = rect1.x + rect1.w + width / 15;
            }
            rect1.x = width / 8;
            rect1.y = rect1.y + rect1.h + height / 17;
        }

        std::string m = checkWinner(matrix, 'X', 'O');

        if (m.size())
        {
            // text initialization begins here
            SDL_Color text_color = {255, 255, 255, 255};
            SDL_Surface *text = TTF_RenderText_Solid(font, m.c_str() , text_color);

            SDL_Texture *text_texture = SDL_CreateTextureFromSurface(render, text);
            // text ends begins here

            // text.w;

            SDL_Rect src = {0, 0, text->w, text->h};
            SDL_Rect dest = {width/2 - text->w*3/2 , height/2 - text->h *3 /2 , text->w * 3, text->h * 3};
            SDL_RenderCopy(render, text_texture, &src, &dest);
            
            // isRunning = false;
        }
        if (checkTie(matrix))
        {
            // text initialization begins here
            SDL_Color text_color = {255, 255, 255, 255};
            SDL_Surface *text = TTF_RenderText_Solid(font, "IT'S  A TIE!!!", text_color);

            SDL_Texture *text_texture = SDL_CreateTextureFromSurface(render, text);
            // text ends begins here

            // text.w;

            SDL_Rect src = {0, 0, text->w, text->h};
            SDL_Rect dest = {0,0, text->w * 2, text->h * 2};
            SDL_RenderCopy(render, text_texture, &src, &dest);
            // isRunning = false;
        }
        // SDL_RenderCopy(render, text_texture, &src, &dest);
        SDL_RenderPresent(render);
    }
}
