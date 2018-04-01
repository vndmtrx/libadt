#ifndef _LIBADT_COMMONS_H
#define _LIBADT_COMMONS_H

#define debug_and_return(str, retval) ({fprintf(stderr, "### %s:%d:%s(): '%s'\n", __FILE__, __LINE__, __func__, str); retval;})

#endif /* _LIBADT_COMMONS_H */
