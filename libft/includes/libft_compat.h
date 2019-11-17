/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_compat.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:31:42 by ksticks           #+#    #+#             */
/*   Updated: 2019/11/17 22:49:11 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_COMPAT_H
# define LIBFT_COMPAT_H

# ifdef _WIN32
#  include <io.h>
# else
#  include <unistd.h>
# endif

# ifndef ULONG

typedef unsigned long		t_ulong;
#  define ULONG t_ulong
# endif

# ifndef ULLONG

typedef unsigned long long	t_ullong;
#  define ULLONG t_ullong
# endif

# ifndef UINT

typedef unsigned int		t_uint;
#  define UINT t_uint
# endif

# ifndef ULLONG_MAX
#  define ULLONG_MAX ULONG_LONG_MAX
# endif

# ifdef __APPLE__
#  define MACOS 1
# else
#  define MACOS 0
# endif

# ifndef LITTLE_ENDIAN
#  define LITTLE_ENDIAN 1234
#  define BIG_ENDIAN 4321
# endif

#endif
