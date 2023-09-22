#include <iostream>
#include <stdexcept>


template <class ValueType> class CircularBuffer {
private:
    ValueType *buffer_;
    int capacity_;
    int size_;
    int firstIndex_;

public:
  CircularBuffer() {
        const int stdCapacity = 2;
        buffer_ = new ValueType[stdCapacity];
        for (int i = 0; i < stdCapacity; i++) {
            buffer_[i] = ValueType();
        }
        capacity_ = stdCapacity;
        size_ = 0;
        firstIndex_ = 0;
    }

    ~CircularBuffer() {
        delete [] buffer_;
    }

    CircularBuffer<ValueType>(const CircularBuffer<ValueType> &cb) {
        buffer_ = new ValueType[cb.capacity_];
        capacity_ = cb.capacity_;
        firstIndex_ = cb.firstIndex_;
        size_ = cb.size_;
        for (int i = 0; i < cb.size_; i++){
            buffer_[(firstIndex_ + i) % capacity_] = cb.buffer_[(cb.firstIndex_ + i) % cb.capacity_];
        }
    }

    // Конструирует буфер заданной ёмкости.
    explicit CircularBuffer(int capacity) {
        buffer_ = new ValueType[capacity];
        this->capacity_ = capacity;
        size_ = 0;
        firstIndex_ = 0;
    }

    // Конструирует буфер заданной ёмкости, целиком заполняет его элементом elem.
    CircularBuffer(int capacity, const ValueType &elem) {
        buffer_ = new ValueType[capacity];
        this->capacity_ = capacity;
        size_ = capacity;
        firstIndex_ = 0;
        for (int i = 0; i < this->capacity_; i++){
            buffer_[(firstIndex_ + i) % this->capacity_] = elem;
        }
    }

    // Доступ по индексу. Не проверяют правильность индекса.
    ValueType &operator[](int i) {
        ValueType &element = buffer_[firstIndex_ + i];
        return element;
    }

    const ValueType &operator[](int i) const {
        const ValueType &element = buffer_[firstIndex_ + i];
        return element;
    }

    // Доступ по индексу. Методы бросают исключение в случае неверного индекса.
    ValueType &at(int i) {
        try{
            ValueType &element = buffer_[firstIndex_ + i];
            return element;
        } catch (const std::out_of_range& other){
            throw other;
        }
    }

    const ValueType &at(int i) const {
        try
        {
            const ValueType &element = buffer_[firstIndex_ + i];
            return element;
        }
        catch (const std::out_of_range &other)
        {
            throw other;
        }
    }

    ValueType &front() { // Ссылка на первый элемент.
        ValueType &firstElement = buffer_[firstIndex_];
        return firstElement;
    }
    ValueType &back() {  // Ссылка на последний элемент.
        ValueType &lastElement = buffer_[(firstIndex_ + size_) % capacity_];
        return lastElement;
    }

    const ValueType &front() const {
        const ValueType &firstElement = buffer_[firstIndex_];
        return firstElement;
    }

    const ValueType &back() const {
        const ValueType &lastElement = buffer_[(firstIndex_ + size_) % capacity_];
        return lastElement;
    }

    // Линеаризация - сдвинуть кольцевой буфер так, что его первый элемент
    // переместится в начало аллоцированной памяти. Возвращает указатель
    // на первый элемент.
    ValueType *linearize() {
        if (firstIndex_ != 0) {
            ValueType *temporaryBuffer = new ValueType[size_];
            for (int i = 0; i < size_; i++) {
              temporaryBuffer[i] = buffer_[(firstIndex_ + i) % capacity_];
            }
            for (int i = 0; i < size_; i++) {
              buffer_[i] = temporaryBuffer[i];
            }
        }
        return buffer_;
    }
    // Проверяет, является ли буфер линеаризованным.
    bool is_linearized() const {
        return firstIndex_ == 0;
    }
    // Сдвигает буфер так, что по нулевому индексу окажется элемент
    // с индексом new_begin.
    void rotate(int new_begin) {
        if (new_begin == 0)
            return;
        ValueType *temporaryBuffer = new ValueType[size_];
        for (int i = 0; i < size_; i++) {
            temporaryBuffer[i] = buffer_[(firstIndex_ + i) % capacity_];
        }
        for (int i = 0; i < size_; i++) {
            buffer_[(capacity_ - new_begin + i) % capacity_] = temporaryBuffer[i];
        }
    }
    // Количество элементов, хранящихся в буфере.
    int size() const {
        return size_;
    }
    bool empty() const {
        return size_ == 0;
    }
    // true, если size() == capacity().
    bool full() const {
        return size() == capacity();
    }
    // Количество свободных ячеек в буфере.
    int reserve() const {
        return capacity_ - size_;
    }
    // ёмкость буфера
    int capacity() const {
        return capacity_;
    }

    void set_capacity(int new_capacity) {
        capacity_ = new_capacity;
        if (capacity_ <= size_)
            size_ = capacity_;

        ValueType *newBuffer = new ValueType[size_];

        for (int i = 0; i < size_; i++) {
            newBuffer[i] = buffer_[(firstIndex_ + i) % capacity_];
        }
        delete[] buffer_;
        buffer_ = newBuffer;
        firstIndex_ = 0;
    }

    // Изменяет размер буфера.
    // В случае расширения, новые элементы заполняются элементом item.
    void resize(int new_size, const ValueType &item = ValueType()) {
        if (size_ < new_size) {
            if (capacity_ <= new_size)
              set_capacity(new_size);
            for (int i = size_ + 1; i < new_size; i++) {
              buffer_[(firstIndex_ +i)%capacity_] = item;
            }
        }
        size_ = new_size;
    }
    // Оператор присваивания.
    CircularBuffer<ValueType> &operator=(const CircularBuffer<ValueType> &cb) {
        buffer_ = new ValueType[cb.capacity_];
        capacity_ = cb.capacity_;
        firstIndex_ = cb.firstIndex_;
        size_ = cb.size_;
        for (int i = 0; i < cb.size_; i++) {
            buffer_[(firstIndex_ + i) % capacity_] = cb.buffer_[(cb.firstIndex_ + i) % cb.capacity_];
        }
    }
    // Обменивает содержимое буфера с буфером cb.
    void swap(CircularBuffer &cb) {
        ValueType *temporaryBuffer = buffer_;
        buffer_ = cb.buffer_;
        cb.buffer_ = temporaryBuffer;
    }

    // Добавляет элемент в конец буфера.
    // Если текущий размер буфера равен его ёмкости, то переписывается
    // первый элемент буфера (т.е., буфер закольцован).
    void push_back(const ValueType &item = ValueType()) {
        if (full()) {
            buffer_[firstIndex_] = item;
            firstIndex_ = (firstIndex_ + 1) % capacity_;
        } else {
            size_++;
            buffer_[firstIndex_ + size_] = item;
        }
    }
    // Добавляет новый элемент перед первым элементом буфера.
    // Аналогично push_back, может переписать последний элемент буфера.
    void push_front(const ValueType &item = ValueType()) {
        if (!full())
            size_++;
        firstIndex_= (capacity_ + firstIndex_ - 1) % capacity_;
        buffer_[firstIndex_] = item;
    }
    // удаляет последний элемент буфера.
    void pop_back() {
        if (!empty())
            size_--;
    }
    // удаляет первый элемент буфера.
    void pop_front() {
        if (!empty()) {
            size_--;
            firstIndex_ = (firstIndex_ + 1) % capacity_;
        }
    }

    // Вставляет элемент item по индексу pos. Ёмкость буфера остается неизменной.
    void insert(int pos, const ValueType &item = ValueType()) {
        try {
            at(pos) = item;
        } catch (const std::out_of_range &other) {
            throw other;
        }
    }
    // Удаляет элементы из буфера в интервале [first, last).
    void erase(int first, int last) {
        for (int i = 0; i < capacity_ - last; i++) {
            buffer_[(firstIndex_ + first + i) % capacity_] =
                buffer_[(firstIndex_ + last + i) % capacity_];
        }
        size_ -= last - first;
    }
    // Очищает буфер.
    void clear() {
        size_ = 0;
        firstIndex_ = 0;
    }
};

template <class X> bool operator==(const CircularBuffer<X> &a, const CircularBuffer<X> &b) {
    if (a.capacity() != b.capacity())
        return false;
    if (a.size() != b.size())
        return false;
    for (int i = 0; i < a.size(); i++) {
        if (a.at(i) != b.at(i))
            return false;
    }
    return true;
}
template <class X> bool operator!=(const CircularBuffer<X> &a, const CircularBuffer<X> &b) {
    if (a == b)
        return false;
    return true;
}