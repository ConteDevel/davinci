#include "spellchecker.h"

#include <sstream>

SpellChecker::SpellChecker(const QString &aff_path, const QString &dic_path) {
    _hunspell_ptr = std::make_unique<Hunspell>(aff_path.toLatin1().data(),
                                               dic_path.toLatin1().data());
}

QString SpellChecker::CorrectedString(const QString &input_string) {
    std::string std_string = input_string.toUtf8().constData();
    std::stringstream string_stream(std_string);

    QString corrected_string = "";

    std::string word;
    while (string_stream >> word) {
        QString q_word = QString::fromStdString(word);
        corrected_string += CorrectedWord(q_word) + " ";
    }
    return std::move(corrected_string);
}

QString SpellChecker::CorrectedWord(const QString &input_word) {
    QString special_character_free_string = _SpecialCharacterFreeWord(input_word);
    char** suggestions;
    const char* word_c_str = special_character_free_string.toLatin1().data();
    (*_hunspell_ptr).suggest(&suggestions, word_c_str);
    bool isWrong = (*_hunspell_ptr).spell(word_c_str) == 0;
    if (isWrong && suggestions) {
        qInfo() << suggestions[0];
        return std::move(QString(suggestions[0]));
    }
    return QString(special_character_free_string);
}

QString SpellChecker::_SpecialCharacterFreeWord(QString input_word) {
    std::vector<std::pair<QString, QString>> replacements {
        {"|", "i"}
    };

    for ( auto const &r : replacements) {
        input_word.replace(r.first, r.second);
    }

    return std::move(input_word);
}




