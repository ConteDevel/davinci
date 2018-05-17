#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H

#include <QtGui>
#include <memory>
#include <hunspell/hunspell.hxx>

class SpellChecker {
public:
    SpellChecker() = delete;
    SpellChecker(const QString& aff_path,
                 const QString& dic_path);

    QString CorrectedString(const QString& input_string);
    QString CorrectedWord(const QString& input_word);

private:
    std::unique_ptr<Hunspell> _hunspell_ptr;
    QString _SpecialCharacterFreeWord(QString input_word);

};

#endif // SPELLCHECKER_H
