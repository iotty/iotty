struct lconv {
	/* Numeric (non-monetary) information */

	char *decimal_point; /* decimal point character */
	char *thousands_sep; /* thousands separator */

	/*
	 * Each element is the number of digits in each group;
	 * elements with higher indices are farther left.
	 * An element with value CHAR_MAX means that no further
	 * grouping is done. An element with value 0 means the
	 * previous element is used for all groups farther left.
	 */
	char *grouping;

	/* Monetary information */

	/*
	 * first three chars are a currency symbol from ISO 4217.
	 * fourth char is the separator. fifth char is '\0'.
	 */
	char *int_curr_symbol;
	char *currency_symbol;   /* local currency symbol */
	char *mon_decimal_point; /* decimal point character */
	char *mon_thousands_sep; /* thousands separator */
	char *mon_grouping;      /* like 'grouping' element (above) */
	char *positive_sign;     /* sign for positive values */
	char *negative_sign;     /* sign for negative values */
	char int_frac_digits;    /* int'l fractional digits */
	char frac_digits;        /* local fractional digits */

	/* 1 if currency_symbol precedes a positive value, 0 if succeeds */
	char p_cs_precedes;

	/* 1 if a space separates currency_symbol from a positive value */
	char p_sep_by_space;

	/* 1 if currency_symbol precedes a negative value, 0 if succeeds */
	char n_cs_precedes;

	/* 1 if a space separates currency_symbol from a negative value */
	char n_sep_by_space;

	/*
	 * Positive and negative sign positions:
	 * 0 Parentheses surround the quantity and currency_symbol
	 * 1 The sign string precedes the quantity and currency_symbol
	 * 2 The sign string follows the quantity and currency_symbol
	 * 3 The sign string immediately precedes the currency_symbol
	 * 4 The sign string immediately follows the currency_symbol
	 */
	char p_sign_posn;
	char n_sign_posn;

	/* 1 if int_curr_symbol precedes a positive value, 0 if succeeds */
	char int_p_cs_precedes;

	/* 1 if a space sparates int_curr_symbol from a positive value */
	char int_p_sep_by_space;

	/* 1 if int_curr_symbol precedes a negative value, 0 if succeeds */
	char int_n_cs_precedes;

	/* 1 if a space separates int_curr_symbol from a negative value */
	char int_n_sep_by_space;

	/*
	 * Positive and negative sign positions:
	 * 0 Parentheses surround the quantity and int_curr_symbol
	 * 1 The sign string precedes the quantity and int_curr_symbol
	 * 2 The sign string follows the quantity and int_curr_symbol
	 * 3 The sign string immediately precedes the int_curr_symbol
	 * 4 The sign string immediately follows the int_curr_symbol
	 */
	char int_p_sign_posn;
	char int_n_sign_posn;
};
