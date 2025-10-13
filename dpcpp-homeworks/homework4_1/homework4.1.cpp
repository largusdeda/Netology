#include <fstream>

class Printable
{
public:
    virtual ~Printable() = default;

    virtual std::string printAsHTML() const = 0;
    virtual std::string printAsText() const = 0;
    virtual std::string printAsJSON() const = 0;
};

class Data : public Printable
{
public:
    enum class Format
    {
        kText,
        kHTML,
        kJSON
    };

    Data(std::string data, Format format)
        : data_(std::move(data)), format_(format) {
    }

    std::string printAsHTML() const override
    {
        if (format_ != Format::kHTML) {
            throw std::runtime_error("Invalid format!");
        }
        return "<html>" + data_ + "<html/>";
    }
    std::string printAsText() const override
    {
        if (format_ != Format::kText) {
            throw std::runtime_error("Invalid format!");
        }
        return data_;
    }
    std::string printAsJSON() const override
    {
        if (format_ != Format::kJSON) {
            throw std::runtime_error("Invalid format!");
        }
        return "{ \"data\": \"" + data_ + "\"}";
    }

private:
    std::string data_;
    Format format_;
};

void saveTo(std::ofstream& file, const Printable& printable, Data::Format format)
{
    switch (format)
    {
    case Data::Format::kText:
        file << printable.printAsText();
        break;
    case Data::Format::kJSON:
        file << printable.printAsJSON();
        break;
    case Data::Format::kHTML:
        file << printable.printAsHTML();
        break;
    }
}

void saveToAsHTML(std::ofstream& file, const Printable& printable) {
    saveTo(file, printable, Data::Format::kHTML);
}

void saveToAsJSON(std::ofstream& file, const Printable& printable) {
    saveTo(file, printable, Data::Format::kJSON);
}

void saveToAsText(std::ofstream& file, const Printable& printable) {
    saveTo(file, printable, Data::Format::kText);
}

/******************************************** ПРИНЦИП ПОДСТАНОВКИ БАРБАРЫ ЛИСКОВ  ********************************************/

// Класс Data не может быть корректно использован вместо класса-родителя Printable, так как изменяет его поведение.
// Например, если у объекта Data формат kText, то вызов метода printAsHTML() выбросит исключение.
// Согласно LSP, объекты подкласса должны быть взаимозаменяемы с объектом базового класса без нарушения корректности программы,
// но в данном случае это не так.

/*****************************************************************************************************************************/

/*********************************************** ПРИНЦИП ОТКРЫТОСТИ/ЗАКРЫТОСТИ ***********************************************/

// Класс Data не закрыт для изменений и не открыт для расширения.
// Если потребуется добавить новый формат, придётся изменять код класса Data - добавить новый метод и изменить перечисление Format.

/*****************************************************************************************************************************/

/*********************************************** ПРИНЦИП РАЗДЕЛЕНИЯ ИНТЕРФЕЙСОВ ***********************************************/

// Интерфейс Printable содержит много методов, которые не всегда будут использоваться.
// Например, если классу-наследнику Data нужно поддерживать только текстовый формат, 
// он всё равно должен реализовывать методы printAsHTML() и printAsJSON().
// Это нарушает принцип разделения интерфейсов, который рекомендует создавать узкоспециализированные интерфейсы, а не общие.


/******************************************************************************************************************************/

/******************************************** ПРИНЦИП ЕДИНСТВЕННОЙ ОТВЕТСТВЕННОСТИ ********************************************/

// Логика форматирования данных находится внутри класса Data, 
// что делает его менее гибким и нарушает принцип единственной ответственности.

/******************************************************************************************************************************/
