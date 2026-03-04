// RESOLVER WHILE DE JOGAR NOVAMENTE

#include <stdio.h>
#include <stdlib.h>
#define TAM 9

void tabuleiro(char *vetorTabuleiro, int tam)
{

  int i, j;

  for (i = 0; i < tam; i++)
  {
    if ((i == 0) || (i == 3) || (i == 6))
    {
      printf("| ");
    }
    if (vetorTabuleiro[i] != '~')
    {
      printf("%c | ", vetorTabuleiro[i]);
    }
    else
    {
      printf("  | ");
    }

    if ((i == 2) || (i == 5) || (i == 8))
    {
      printf("\n");
      if ((i == 2) || (i == 5))
      {
        for (j = 0; j < 13; j++)
        {
          printf("-");
        }
        printf("\n");
      }
    }
  }
}

int verificaJogada(int jogada, char *vetorTabuleiro, int tam)
{

  char verifica;

  verifica = vetorTabuleiro[jogada - 1];

  if (jogada <= tam && jogada > 0)
  {
    if (verifica == '~')
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    return 0;
  }
}

void fvezO(char *vetorTabuleiro, int tam)
{

  int jogada, jogadaConcluida = 1, verifica;

  while (jogadaConcluida == 1)
  {
    printf("Em qual casa 'O' deseja jogar?(1-9)");
    scanf("%d", &jogada);
    verifica = verificaJogada(jogada, vetorTabuleiro, TAM);
    if (verifica == 1)
    {
      vetorTabuleiro[jogada - 1] = 'O';
      jogadaConcluida = 0;
    }
    else
    {
      printf("Jogada invalida\n");
    }
  }
}

void fvezX(char *vetorTabuleiro, int tam)
{

  int jogada, jogadaConcluida = 1, verifica, valorRecebido;

  while (jogadaConcluida == 1)
  {
    printf("Em qual casa 'X' deseja jogar?(1-9)");
    scanf("%d", &jogada);
    verifica = verificaJogada(jogada, vetorTabuleiro, TAM);
    if (verifica == 1)
    {
      vetorTabuleiro[jogada - 1] = 'X';
      jogadaConcluida = 0;
    }
    else
    {
      printf("Jogada invalida\n");
    }
  }
}

int verificaColuna1(char *vetorTabuleiro, int tam)
{

  if (vetorTabuleiro[0] + vetorTabuleiro[3] + vetorTabuleiro[6] == 'O' + 'O' + 'O')
  {
    return 1;
  }
  else if (vetorTabuleiro[0] + vetorTabuleiro[3] + vetorTabuleiro[6] == 'X' + 'X' + 'X')
  {
    return 2;
  }
  else
  {
    return 0;
  }
}

int verificaColuna2(char *vetorTabuleiro, int tam)
{

  if (vetorTabuleiro[1] + vetorTabuleiro[4] + vetorTabuleiro[7] == 'O' + 'O' + 'O')
  {
    return 1;
  }
  else if (vetorTabuleiro[1] + vetorTabuleiro[4] + vetorTabuleiro[7] == 'X' + 'X' + 'X')
  {
    return 2;
  }
  else
  {
    return 0;
  }
}

int verificaColuna3(char *vetorTabuleiro, int tam)
{

  if (vetorTabuleiro[2] + vetorTabuleiro[5] + vetorTabuleiro[8] == 'O' + 'O' + 'O')
  {
    return 1;
  }
  else if (vetorTabuleiro[2] + vetorTabuleiro[5] + vetorTabuleiro[8] == 'X' + 'X' + 'X')
  {
    return 2;
  }
  else
  {
    return 0;
  }
}

int verificaLinha1(char *vetorTabuleiro, int tam)
{

  if (vetorTabuleiro[0] + vetorTabuleiro[1] + vetorTabuleiro[2] == 'O' + 'O' + 'O')
  {
    return 1;
  }
  else if (vetorTabuleiro[0] + vetorTabuleiro[1] + vetorTabuleiro[2] == 'X' + 'X' + 'X')
  {
    return 2;
  }
  else
  {
    return 0;
  }
}

int verificaLinha2(char *vetorTabuleiro, int tam)
{

  if (vetorTabuleiro[3] + vetorTabuleiro[4] + vetorTabuleiro[5] == 'O' + 'O' + 'O')
  {
    return 1;
  }
  else if (vetorTabuleiro[3] + vetorTabuleiro[4] + vetorTabuleiro[5] == 'X' + 'X' + 'X')
  {
    return 2;
  }
  else
  {
    return 0;
  }
}

int verificaLinha3(char *vetorTabuleiro, int tam)
{

  if (vetorTabuleiro[6] + vetorTabuleiro[7] + vetorTabuleiro[8] == 'O' + 'O' + 'O')
  {
    return 1;
  }
  else if (vetorTabuleiro[6] + vetorTabuleiro[7] + vetorTabuleiro[8] == 'X' + 'X' + 'X')
  {
    return 2;
  }
  else
  {
    return 0;
  }
}

int verificaDiagonal1(char *vetorTabuleiro, int tam)
{

  if (vetorTabuleiro[0] + vetorTabuleiro[4] + vetorTabuleiro[8] == 'O' + 'O' + 'O')
  {
    return 1;
  }
  else if (vetorTabuleiro[0] + vetorTabuleiro[4] + vetorTabuleiro[8] == 'X' + 'X' + 'X')
  {
    return 2;
  }
  else
  {
    return 0;
  }
}

int verificaDiagonal2(char *vetorTabuleiro, int tam)
{

  if (vetorTabuleiro[2] + vetorTabuleiro[4] + vetorTabuleiro[6] == 'O' + 'O' + 'O')
  {
    return 1;
  }
  else if (vetorTabuleiro[2] + vetorTabuleiro[4] + vetorTabuleiro[6] == 'X' + 'X' + 'X')
  {
    return 2;
  }
  else
  {
    return 0;
  }
}

int verificaTodasAsCasas(char *vetorTabuleiro, int tam)
{

  if (vetorTabuleiro[0] != '~' && vetorTabuleiro[1] != '~' && vetorTabuleiro[2] != '~' && vetorTabuleiro[3] != '~' && vetorTabuleiro[4] != '~' && vetorTabuleiro[5] != '~' && vetorTabuleiro[6] != '~' && vetorTabuleiro[7] != '~' && vetorTabuleiro[8] != '~')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int jogarDeNovo(char *vetorTabuleiro, int tam)
{

  char jogarDeNovo;
  int i;

  printf("\n\nDeseja Jogar Novamente?(S/N)\n");
  scanf(" %c", &jogarDeNovo);

  if ((jogarDeNovo == 'S') || (jogarDeNovo == 's'))
  {
    for (i = 0; i < tam; i++)
    {
      vetorTabuleiro[i] = '~';
    }
  }
  else if ((jogarDeNovo == 'N') || (jogarDeNovo == 'n'))
  {
    return 0;
  }
}

int main()
{

  char vetorTabuleiro[9] = {'~', '~', '~', '~', '~', '~', '~', '~', '~'};
  int jogoConcluido = 0, vezO = 1, vezX = 0, vc1, vc2, vc3, vl1, vl2, vl3, vd1, vd2, vtc, jogarNovamente;
  int i;

  while (jogoConcluido == 0)
  {

    if (vezO == 1)
    {
      tabuleiro(vetorTabuleiro, TAM);
      fvezO(vetorTabuleiro, TAM);
      vezO = 0;
    }
    else if (vezO == 0)
    {
      vezO = 1;
    }
    if (vezX == 1)
    {
      tabuleiro(vetorTabuleiro, TAM);
      fvezX(vetorTabuleiro, TAM);
      vezX = 0;
    }
    else if (vezX == 0)
    {
      vezX = 1;
    }
    vc1 = verificaColuna1(vetorTabuleiro, TAM);
    vc2 = verificaColuna2(vetorTabuleiro, TAM);
    vc3 = verificaColuna3(vetorTabuleiro, TAM);
    vl1 = verificaLinha1(vetorTabuleiro, TAM);
    vl2 = verificaLinha2(vetorTabuleiro, TAM);
    vl3 = verificaLinha3(vetorTabuleiro, TAM);
    vd1 = verificaDiagonal1(vetorTabuleiro, TAM);
    vd2 = verificaDiagonal2(vetorTabuleiro, TAM);
    vtc = verificaTodasAsCasas(vetorTabuleiro, TAM);

    printf("\033[H\033[J");

    if (vc1 == 1 || vc2 == 1 || vc3 == 1 || vl1 == 1 || vl2 == 1 || vl3 == 1 || vd1 == 1 || vd2 == 1)
    {
      tabuleiro(vetorTabuleiro, TAM);
      printf("JOGADOR 'O' GANHOU, PARABENS 'O'!!!");
      jogarNovamente = jogarDeNovo(vetorTabuleiro, TAM);
      printf("\033[H\033[J");
      if (jogarNovamente == 0)
      {
        jogoConcluido = 1;
      }
    }
    else if (vc1 == 2 || vc2 == 2 || vc3 == 2 || vl1 == 2 || vl2 == 2 || vl3 == 2 || vd1 == 2 || vd2 == 2)
    {
      tabuleiro(vetorTabuleiro, TAM);
      jogarNovamente = jogarDeNovo(vetorTabuleiro, TAM);
      printf("\033[H\033[J");
      if (jogarNovamente == 0)
      {
        jogoConcluido = 1;
      }
    }
    else if (vtc == 1)
    {
      tabuleiro(vetorTabuleiro, TAM);
      jogarNovamente = jogarDeNovo(vetorTabuleiro, TAM);
      printf("\033[H\033[J");
      if (jogarNovamente == 0)
      {
        jogoConcluido = 1;
      }
    }
  }
}
