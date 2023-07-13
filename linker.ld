ENTRY(start)

SECTIONS
{
	/* Begin sections at address 1 Megabyte. */
	. = 1M;
	
	/* All sections will be aligned by 4KiB for paging. */
	
	/* Multiboot */
	.rodata BLOCK(4K) : ALIGN(4K)
	{
		*(.multiboot)
	}

	/* Executable */
	.text BLOCK(4K) : ALIGN(4K)
	{
		*(.text)
	}
	
	/* Read-only data  */
	.rodata BLOCK(4K) : ALIGN(4K)
	{
		*(.rodata)
	}
	
	/* Read-write data */
	.data BLOCK(4K) : ALIGN(4K)
	{
		*(.data)
	}

	/* Read-write uninitialized data & the Stack */
	.bss BLOCK(4K) : ALIGN(4K)
	{
		*(COMMON)
		*(.bss)
	}
}

