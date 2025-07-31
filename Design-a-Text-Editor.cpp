class TextEditor {
    list<char> text;
    list<char>::iterator cursor;

public:
    TextEditor() {
        cursor = text.begin();
    }

    void addText(string s) {
        for (char c : s) {
            cursor = text.insert(cursor, c);
            ++cursor;
        }
    }

    int deleteText(int k) {
        int deleted = 0;
        while (k > 0 && cursor != text.begin()) {
            cursor = text.erase(--cursor);
            k--;
            deleted++;
        }
        return deleted;
    }

    string cursorLeft(int k) {
        while (k > 0 && cursor != text.begin()) {
            --cursor;
            --k;
        }
        return getLast10();
    }

    string cursorRight(int k) {
        while (k > 0 && cursor != text.end()) {
            ++cursor;
            --k;
        }
        return getLast10();
    }

private:
    string getLast10() {
        string res;
        auto it = cursor;
        int count = 0;
        while (it != text.begin() && count < 10) {
            --it;
            res += *it;
            count++;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */