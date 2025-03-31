#include "eventlist.h"

Event* create_event(time_t timestamp, int duration) {
    Event* new_event = (Event*)malloc(sizeof(Event));
    if (new_event == NULL) {
        fprintf(stderr, "Error: no se pudo asignar memoria para el evento\n");
        exit(EXIT_FAILURE);
    }
    new_event->timestamp = timestamp;
    new_event->duration = duration;
    new_event->prev = NULL;
    new_event->next = NULL;
    return new_event;
}

EventList* create_event_list() {
    EventList* list = (EventList*)malloc(sizeof(EventList));
    if (list == NULL) {
        fprintf(stderr, "Error: no se pudo asignar memoria para la lista de eventos\n");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    list->tail = NULL;
    return list;
}

int is_expired(Event* event, time_t current_time){ //Función para verificar si expiraron o no los eventos.
    return (event->timestamp+event->duration <= current_time);
}

void add_event(EventList* list, time_t timestamp, int duration) {
    Event* event = create_event(timestamp, duration);

    if (list->head ==NULL){ //Si el puntero a la cabeza de lista es nulo, la lista está vacía.
        list->head = event;
        list->tail = event; //Ahora, este nuevo evento es el primero y último de la lista.
    }
    else { //En caso que no esté vacía, añado el evento al final.
        list->tail->next = event;
        event->prev = list->tail;
        list->tail = event;
    }
}

void remove_expired_events(EventList* list, time_t current_time) {
    Event* current_event = list->head;

    while (current_event!=NULL){

        if (is_expired(current_event,current_time)){ //Si expiró, hay que removerlo.
            Event* next = current_event-> next;
            if (current_event ->prev != NULL) current_event->prev-> next = current_event->next; //El puntero que apunta a current como siguiente pasa a apuntar como sig a al sig de current.
            if (current_event -> next != NULL) current_event-> next->prev = current_event->prev; //Que el puntero que apuntaba a curent como previo, pase a apuntar al previo de current como previo.
            if (current_event -> prev==NULL) list-> head = current_event->next; //Redirigo en caso de que fuese el primero.
            if (current_event -> next == NULL) list-> tail = current_event ->prev; // "" "" "" "" "" "" el último.
            free(current_event);
            current_event = next;
            }

        else{
            current_event = current_event->next;
        }
        }   
    }

void print_current_events(EventList* list, time_t current_time) {
    Event* current = list->head;
    printf("Eventos actuales (después de eliminar expirados):\n");
    while (current != NULL) {
        printf("Evento en %ld con duración %d\n", current->timestamp, current->duration);
        current = current->next;
    }
}

void destroy_list(EventList* list) {
    Event* current_node = list->head;

    while (current_node!=NULL){
        Event* next_node = current_node->next;
        free(current_node);
        current_node = next_node; //Para que el while siga comparando.
    }
    free(list);
}
