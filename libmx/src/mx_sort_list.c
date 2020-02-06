#include "libmx.h"

_Bool cmp(void *a, void *b) {
     if (a > b) return 1;
     else return 0;
     
 }
t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    if(!lst && !cmp)
    return NULL;
    void *swp;
    for(t_list *i = lst; i->next; i = i->next) {
        for(t_list *j = lst; j; j = j->next) {
            if(cmp(i->data, j->data)) {
                swp = i->data;
                i->data = j->data;
                j->data = swp;
            }
        }
    }
    return swp;
}



