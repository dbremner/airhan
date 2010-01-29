int a;

// place holder

/* 
void * memmove(void * dst, void * src, size_t count)
;       {
;               void * ret = dst;
;
;               if (dst <= src || dst >= (src + count)) {

;                       while (count--)
;                               *dst++ = *src++;
;                       }
;               else {

;                       dst += count - 1;
;                       src += count - 1;
;
;                       while (count--)
;                               *dst-- = *src--;
;                       }
;
               return(ret);
      }
     */