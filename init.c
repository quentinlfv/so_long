#include "so_long.h"

void	init_struct(t_game *game)
{
	game->player.x = 0;
	game->player.y = 0;
	game->player.status = 0;
	game->player.count_moves = 0;
	game->size.line = 0;
	game->size.column = 0;
	game->nbr_item = 0;
	game->exit_status = 0;
	game->map = NULL;
}
