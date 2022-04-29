#ifndef FILESTATE_H
#define FILESTATE_H

// структурa FileState нужна для представления состояния файла с двумя полями
struct FileState {
    bool operator!=(const FileState& other ) { // определяем оператор неравно для того, чтобы уведомлять об изменениях
        if (this == &other) {
            return false;
        }
        return exists != other.exists || size != other.size;
    }
    bool exists; // факт существования
    unsigned long long size; // размер
};

#endif // FILESTATE_H
