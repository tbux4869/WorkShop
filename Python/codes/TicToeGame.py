import random as rd
import numpy as np

# define functions to show the game board
def area(board):
    print(board[0, 0], '|', board[0, 1], '|', board[0, 2])
    print('---------')
    print(board[1, 0], '|', board[1, 1], '|', board[1, 2])
    print('---------')
    print(board[2, 0], '|', board[2, 1], '|', board[2, 2])


# ask for the names of the players
def askName():
    for i in np.arange(2):
        print('Enter Player%d name :' % (i + 1))
        player = input()
        print('Dear ' + player + ',welcome you to the game!')


#ask for which letter are players choosing
def askLetter():
    letter=''
    while not(letter=='X'or letter=='O'):
        print('Player1 , please choose letter')
        print('Do you wanna be X or O ?')
        letter=input().upper()
    if letter=='X':
        return 'Player1 : X & Player2 : O'
    else:
        return 'Player1 : O & Player2 : X'

# decide who goes first
def whogoesFirst():
    if rd.randint(0, 1) == 0:
        print('It is randomly decided that Player1 goes first!')
    else:
        print('It is randomly decided that Player2 goes first!')


#define players to move
def getMove(board,letter,move_x,move_y):
    board[move_x,move_y]=letter

#check if it is a legal move on the board
def legalMove(board,move_x,move_y):
    return board[move_x,move_y]==''

#define winner
def isFull(board):
    for i in np.arange(3):
        for j in np.arange(3):
            if legalMove(board,i,j):
                return False
    return True

def hasWon(board, i):
    if i == 1:
                if board[0,0] == board[0,1] == board[0,2] == 'X':
                    print('Player 1 has won!')
                    return True
                elif board[1,0] == board[1,1] == board[1,2] == 'X':
                    print('Player 1 has won!')
                    return True
                elif board[2,0] == board[2,1] == board[2,2] == 'X':
                    print('Player 1 has won!')
                    return True
                elif board[0,0] == board[1,0] == board[2,0] == 'X':
                    print('Player 1 has won!')
                    return True
                elif board[1,0] == board[1,1] == board[1,2] == 'X':
                    print('Player 1 has won!')
                    return True
                elif board[2,0] == board[2,1] == board[2,2] == 'X':
                    print('Player 1 has won!')
                    return True
                elif board[2,0] == board[1,1] == board[0,2] == 'X':
                    print('Player 1 has won!')
                    return True
                elif board[0,0] == board[1,1] == board[2,2] == 'X':
                    print('Player 1 has won!')
                    return True
                else:
                    print('Player1 : not yet winning.')
                    return False
    if i == 2:
                if board[0,0] == board[0,1] == board[0,2] == 'O':
                    print('Player 2 has won!')
                    return True
                elif board[1,0] == board[1,1] == board[1,2] == 'O':
                    print('Player 2 has won!')
                    return True
                elif board[2,0] == board[2,1] == board[2,2] == 'O':
                    print('Player 2 has won!')
                    return True
                elif board[0,0] == board[1,0] == board[2,0] == 'O':
                    print('Player 2 has won!')
                    return True
                elif board[1,0] == board[1,1] == board[1,2] == 'O':
                    print('Player 2 has won!')
                    return True
                elif board[2,0] == board[2,1] == board[2,2] == 'O':
                    print('Player 2 has won!')
                    return True
                elif board[2,0] == board[1,1] == board[0,2] == 'O':
                    print('Player 2 has won!')
                    return True
                elif board[0,0] == board[1,1] == board[2,2] == 'O':
                    print('Player 2 has won!')
                    return True
                else:
                    print('Player2 : not yet winning.')
                    return False

#make players to move
def timetoMove(board):
    move_x=''
    move_y=''
    letter=''
    while isFull(board)==False and hasWon(board,1)==False and hasWon(board,2)==False:
        if(move_x =='' and move_y =='' and letter ==''):
          print('Please decide your next move !')
          print('Please decide your next move_x !')
          move_x=input()
          print('Please decide your next move_y !')
          move_y=input()
          print('Please enter your  letter !')
          letter=input().upper()
          while legalMove(board,move_x,move_y)==False:
              print('This move is illegal, please restart moving !')
              print('Please decide your next move !')
              print('Please decide your next move_x !')
              move_x = input()
              print('Please decide your next move_y !')
              move_y = input()
              print('Please enter your  letter !')
              letter = input().upper()
          else:
              print('you choose  ' + move_x  + move_y + '  as  ' + "'"+letter+"'")
              getMove(board, letter, move_x, move_y)
              print(area(board))
              move_x = ''
              move_y = ''
              letter = ''
    else:
        if(isFull(board)==True and hasWon(board,1)==False and hasWon(board,2)==False):
             print("DRAW!!! There is no winner!")
        else:
            isFull(board)
            hasWon(board, 1)
            hasWon(board, 2)


#start
print('>>Muhan Entertainment present<<')
print('>>Jiawei(Zachary) Li creation<<')
print('!Tic Toe War !')
print('Welcome to Tic Toe  Game world! :>')
print('In this game, Player1 uses X and Player2 uses O')
askName()
print('Now it is time to decide who goes first')
whogoesFirst()

board = np.array([['', '', ''], ['', '', ''], ['', '', '']], dtype=str)

print('All the preparations are done! Let us take a look at our battle field!')
area(board)
print('Now! Here we GO! :>')
timetoMove(board)























