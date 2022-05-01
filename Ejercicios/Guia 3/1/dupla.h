typedef struct {
    int pri, seg;
} dupla;


dupla crear(int pri, int seg) {
    dupla d;
    d.pri = pri;
    d.seg = seg;
    return d;
}

int primero(dupla d) {
    return d.pri;
}

int segundo(dupla d) {
    return d.seg;
}
