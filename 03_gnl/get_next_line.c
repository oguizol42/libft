/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:23:57 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/25 16:41:24 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*str;

	return(str);
}

/*
ssize_t read(int fd, void *buf, size_t count);
ssize_t read(int fd, stash, BUFFER_SIZE);

struct typedef  


- Verifier si une structure existe deja pour le fd demande
	- Si oui -> prevoir une allocation memoire augmentee de BUFFER_SIZE + 1 (pour ajout d'un '\0' qui servira de marqueur)
	- Si non -> creer une structure avec un buffet char* de taille BUFFER_SIZE +1 et l'ajouter dans la liste chainee
	
- Faire un read en rangeant le resultat en fin du buffet

- Tester si une ligne complete est presente dans le buffet
	- Si oui -> etape suivante
	- Si non -> reboucler sur read et reallocation memoire du buffer jusqu'a atteindre '\n' ou EOF (-1)

- Recuperer la ligne a envoyer dans le buffet.
- Reajuster le contenu et la taille du buffet pour n'avoir plus que les caracteres non envoyes:
	=> Si buffet vide apres recuperation de la ligne, 
	   retirer le noeud de la chaine et liberer l'espace memoire du noeud et ses composants

	
malloc
free



*/