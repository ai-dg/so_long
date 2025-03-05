/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:49:00 by dagudelo          #+#    #+#             */
/*   Updated: 2024/04/12 12:25:34 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_print
{
	int	hash;
	int	space;
	int	space_width;
	int	plus;
	int	minus;
	int	width_nbr;
	int	point;
	int	point_width;
	int	zero;
	int	zero_width;
	int	width_minus;
}		t_print;

int		ft_printf(const char *str, ...);
int		ft_char(char c, t_print flag);
int		ft_hex(unsigned long long nbr, const char index, t_print flag);
void	print_width_nbr_1(const char *nbr, t_print flag, int *len_str,
			char index);
int		ft_int(int c, t_print flag);
void	print_width_nbr_1_int(const char *nbr, t_print flag, int *len_str,
			int *c);
int		ft_unsigned(unsigned int c, t_print flag);
void	print_width_nbr_1_uint(const char *nbr, t_print flag, int *len_str,
			unsigned int *c);
int		ft_string(char *str, t_print flag);
void	ft_space_plus(t_print flag, int *len_str, int *c);
void	ft_minus(t_print flag, int *len_str);
void	ft_hash(t_print flag, const char *nbr, int *len_str, char index);
int		max(int a, int b);
void	ft_set_list(t_print *flag);
void	print_width_point_int(t_print flag, const char *nbr, int *len_str,
			int *c);
void	print_width_point(t_print flag, const char *nbr, int *len_str);
void	print_padding(int *len_str, int count, char padding_char);
void	print_number(const char *nbr, int *len_str);
int		ft_space_count(const char *str);
char	*ft_itoa_flag(long long unsigned int n);
int		ft_check_list(char c, char *base);
void	ft_str_extract(char c, char *str);
int		ft_atoi_flag(const char *str, int *index);
void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlen(const char *s);
int		ft_char_sub(char c);

#endif
