// SPDX - License - Identifier:GPL - 2.0
/*
 * This is a simple Reed-Solomon encoder
 *
 * (C) Cliff Hones 2004
 */

#ifndef __REEDSOL_H
#define __REEDSOL_H

void	rs_init_gf(int poly);
void	rs_init_code(int nsym, int index);
void	rs_encode(int len, const unsigned char *data, unsigned char *res);

#endif	/* __REEDSOL_H */
