// SPDX - License - Identifier:GPL - 2.0
/*
 * IEC16022 bar code generation Adrian Kennard, Andrews & Arnold Ltd with
 * help from Cliff Hones on the RS coding
 *
 * (c) 2004 Adrian Kennard, Andrews & Arnold Ltd (c) 2006-2007 Stefan Schmidt
 * <stefan@datenfreihafen.org>
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 51
 * Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 *
 */

#define	IEC16022_FLAG_GS1 1
#define	MAXBARCODE 3116

unsigned char  *
iec16022ecc200(int *Wptr, int *Hptr, char **encodingptr,
    int barcodelen, const unsigned char *barcode,
    int *lenp, int *maxp, int *eccp);

unsigned char  *
iec16022ecc200f(int *Wptr, int *Hptr, char **encodingptr,
    int barcodelen, const unsigned char *barcode,
    int *lenp, int *maxp, int *eccp, int flags);
