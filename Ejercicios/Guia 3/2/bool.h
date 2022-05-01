typedef struct {
    int b;
} booleano;

booleano crear(int a) {
    booleano b;
    b.b = a ? 1 : 0;
    return b;
}

booleano andd(booleano b1, booleano b2) {
    booleano b;
    b.b = b1.b && b2.b;
    return b;
}

booleano orr(booleano b1, booleano b2) {
    booleano b;
    b.b = b1.b || b2.b;
    return b;
}

booleano nott(booleano b1) {
    booleano b;
    b.b = !b1.b;
    return b;
}

int val(booleano b) {
    return b.b;
}
