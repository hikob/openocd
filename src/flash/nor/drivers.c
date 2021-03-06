/***************************************************************************
 *   Copyright (C) 2009 Zachary T Welch <zw@superlucidity.net>             *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include "imp.h"

extern struct flash_driver lpc2000_flash;
extern struct flash_driver lpc288x_flash;
extern struct flash_driver lpc2900_flash;
extern struct flash_driver cfi_flash;
extern struct flash_driver at91sam3_flash;
extern struct flash_driver at91sam7_flash;
extern struct flash_driver str7x_flash;
extern struct flash_driver str9x_flash;
extern struct flash_driver aduc702x_flash;
extern struct flash_driver stellaris_flash;
extern struct flash_driver str9xpec_flash;
extern struct flash_driver stm32f1x_flash;
extern struct flash_driver stm32f2x_flash;
extern struct flash_driver stm32lx_flash;
extern struct flash_driver tms470_flash;
extern struct flash_driver ecosflash_flash;
extern struct flash_driver ocl_flash;
extern struct flash_driver pic32mx_flash;
extern struct flash_driver avr_flash;
extern struct flash_driver faux_flash;
extern struct flash_driver virtual_flash;
extern struct flash_driver stmsmi_flash;
extern struct flash_driver em357_flash;
extern struct flash_driver dsp5680xx_flash;
extern struct flash_driver fm3_flash;
extern struct flash_driver kinetis_flash;

/**
 * The list of built-in flash drivers.
 * @todo Make this dynamically extendable with loadable modules.
 */
static struct flash_driver *flash_drivers[] = {
	&lpc2000_flash,
	&lpc288x_flash,
	&lpc2900_flash,
	&cfi_flash,
	&at91sam7_flash,
	&at91sam3_flash,
	&str7x_flash,
	&str9x_flash,
	&aduc702x_flash,
	&stellaris_flash,
	&str9xpec_flash,
	&stm32f1x_flash,
	&stm32f2x_flash,
	&stm32lx_flash,
	&tms470_flash,
	&ecosflash_flash,
	&ocl_flash,
	&pic32mx_flash,
	&avr_flash,
	&faux_flash,
	&virtual_flash,
	&stmsmi_flash,
	&em357_flash,
	&fm3_flash,
	&dsp5680xx_flash,
	&kinetis_flash,
	NULL,
};

struct flash_driver *flash_driver_find_by_name(const char *name)
{
	for (unsigned i = 0; flash_drivers[i]; i++)
	{
		if (strcmp(name, flash_drivers[i]->name) == 0)
			return flash_drivers[i];
	}
	return NULL;
}
