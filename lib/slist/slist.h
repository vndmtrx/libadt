#ifndef _LIBADT_SLIST_H
#define _LIBADT_SLIST_H

typedef struct _slist_root slist_root;

typedef struct _slist_node slist_node;

void slist_create(slist_root **list);

void slist_destroy(slist_root **list);

int slist_insert_el(slist_root *list, slist_node *current, const void *data);

int slist_rem_el(slist_root *list, slist_node *current, void **data);

int slist_size(slist_root *list);

int slist_head(slist_root *list);

int slist_tail(slist_root *list);

#define slist_empty(list) ((list)->size == 0))

#define slist_el_is_head(list, element) ((((element)->root == (list)) && ((element) == (list)->head)) ? 1 : 0)

#define slist_el_is_tail(list, element) ((((element)->root == (list)) && ((element)->next == NULL)) ? 1 : 0)

#define slist_data(element) ((element)->data)

#define slist_next(element) ((element)->next)

#endif
