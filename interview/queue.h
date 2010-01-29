/*

Copyright (c) 2005-2008, Simon Howard

Permission to use, copy, modify, and/or distribute this software 
for any purpose with or without fee is hereby granted, provided 
that the above copyright notice and this permission notice appear 
in all copies. 

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL 
WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE 
AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR 
CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM 
LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, 
NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN      
CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. 

 */

#ifndef ALGORITHM_QUEUE_H
#define ALGORITHM_QUEUE_H

#ifdef __cplusplus
extern "C" {
#endif


typedef struct _Queue Queue;
typedef void *QueueValue;

#define QUEUE_NULL ((void *) 0)

Queue *queue_new(void);

void queue_free(Queue *queue);

int queue_push_head(Queue *queue, QueueValue data);

QueueValue queue_pop_head(Queue *queue);

QueueValue queue_peek_head(Queue *queue);

int queue_push_tail(Queue *queue, QueueValue data);

QueueValue queue_pop_tail(Queue *queue);

QueueValue queue_peek_tail(Queue *queue);

int queue_is_empty(Queue *queue);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef ALGORITHM_QUEUE_H */