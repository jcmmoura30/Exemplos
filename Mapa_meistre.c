#include <stdio.h>
#include <stdbool.h>

int main() {
  int width, height; // Largura e altura do mapa
  char map[100][100]; // Matriz de caracteres que representa o mapa
  int current_x, current_y; // Posição atual no mapa (coordenadas x e y)

  // Leitura das dimensões do mapa
  scanf("%d", &width);
  scanf("%d", &height);

  // Leitura do mapa
  for (int i = 0; i < height; i++) {
    scanf("%s", map[i]);
  }

  // Inicialização da posição inicial
  current_x = 0;
  current_y = 0;

  // Simulação do movimento
  bool valid = true; // Flag para indicar se o mapa é válido ou não
  while (valid) {
    if (current_x < 0 || current_x >= width || current_y < 0 || current_y >= height) {
      // Fora dos limites do mapa
      valid = false;
    } else {
      // Processamento do caractere na posição atual
      switch (map[current_y][current_x]) {
        case '>':
          current_x++;
          break;
        case '<':
          current_x--;
          break;
        case '^':
          current_y--;
          break;
        case 'v':
          current_y++;
          break;
        case '*':
          // Encontrou o baú!
          printf("*\n");
          return 0;
        case '.':
          // Move para a próxima posição
          break;
        default:
          // Caractere inválido
          valid = false;
      }
    }
  }

  // Mapa inválido
  if (!valid) {
    printf("!\n");
  }

  return 0;
}
