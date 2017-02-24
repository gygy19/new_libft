/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 15:42:27 by jguyet            #+#    #+#             */
/*   Updated: 2017/02/23 15:42:29 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define BOOLEAN int
#define HASH_MAP_START_SIZE 1

typedef struct		s_hash
{
	void			*data;
	void			*key;
	struct s_hash	*next;
}					t_hash;

typedef struct	s_hashmap
{
	t_hash		**hashTable;
	BOOLEAN		(*add)();
	void		*(*get)();
	int			(*size)();
	void		(*toString)();
	int			map_size;
	int			type;
}				t_hashmap;

typedef enum	e_boolean
{
	true = 1,
	false = 0
}				t_boolean;

static int	parseKey(t_hashmap *table, void *key)
{
	unsigned long int hashkey;
	int i;

	i = 0;
	hashkey = 0;
	if (table->type == 's')
	{
		while (hashkey < ULONG_MAX && (*(char*)key))
		{
			hashkey = hashkey << 8;
			hashkey += (*(char*)key);
			i++;
			key++;
		}
	}
	else if (table->type == 'i')
		hashkey = (int)key;
	return (hashkey % table->map_size);
}

BOOLEAN	add_Hash(t_hashmap *table, void *key, void *data)
{
	t_hash	*new;
	int		hashindex;
	t_hash	**element;

	if (!(new = (t_hash*)malloc(sizeof(struct s_hash))))
		return (false);
	new->key = key;
	new->data = data;
	new->next = NULL;
	hashindex = parseKey(table, key);
	element = &table->hashTable[hashindex];
	if (*element != NULL)
	{
		while ((*element)->next != NULL)
			element = &(*element)->next;
		(*element)->next = new; 
	}
	else
		table->hashTable[hashindex] = new;
	return (true);
}

void	*get_Hash_value(t_hashmap *table, void *key)
{
	int		hashindex;
	t_hash	*element;

	hashindex = parseKey(table, key);
	if (table->hashTable[hashindex] != NULL)
	{
		element = table->hashTable[hashindex];
		while (element != NULL)
		{
			if (element->key == key)
				return (element->data);
			element = element->next;
		}
	}
	return (NULL);
}

int		get_Hash_size(t_hashmap *table)
{
	return (0);
}

void	toString_hashTable()
{

}

void		clear(t_hashmap *table)
{
	int		i;
	t_hash	*element;
	t_hash	**tmp;

	i = 0;
	while (i < table->map_size)
	{
		if (table->hashTable[i] != NULL)
		{
			element = table->hashTable[i];
			while (element != NULL)
			{
				tmp = &element;
				element = element->next;
				free(&(*tmp)->data);
				free(tmp);
			}
		}
		i++;
	}
}

t_hashmap	*newIntegerhashmap()
{
	t_hashmap	*new;
	int			i;

	i = -1;
	if (!(new = (t_hashmap*)malloc(sizeof(t_hashmap))))
		return (NULL);
	new->add = add_Hash;
	new->get = get_Hash_value;
	new->size = get_Hash_size;
	new->toString = toString_hashTable;
	new->map_size = HASH_MAP_START_SIZE;
	new->type = 'i';
	if (!(new->hashTable = (t_hash**)malloc(sizeof(t_hash*) * new->map_size)))
		return (NULL);
	while (i++ < new->map_size)
		new->hashTable[i] = NULL;
	return (new);
}

t_hashmap	*newStringhashmap()
{
	t_hashmap	*new;
	int			i;

	i = -1;
	if (!(new = (t_hashmap*)malloc(sizeof(t_hashmap))))
		return (NULL);
	new->add = add_Hash;
	new->get = get_Hash_value;
	new->size = get_Hash_size;
	new->toString = toString_hashTable;
	new->map_size = HASH_MAP_START_SIZE;
	new->type = 's';
	if (!(new->hashTable = (t_hash**)malloc(sizeof(t_hash*) * new->map_size)))
		return (NULL);
	while (i++ < new->map_size)
		new->hashTable[i] = NULL;
	return (new);
}

int		main(int argc, char **argv)
{
	char *test = "test";
	char *test1 = "test1";
	char *test2 = "test2";
	t_hashmap *map = newStringhashmap();
	map->add(map, "0", test2);
	map->add(map, "1", test1);
	map->add(map, "2", test2);
	printf("%s\n", map->get(map, "0"));
	printf("%s\n", map->get(map, "1"));
	printf("%s\n", map->get(map, "2"));
	return (0);
}