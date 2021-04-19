// overrideとfinal

// override: オーバーライドを明示的に宣言するキーワード
// final: これ以上継承させないことを明示的に宣言するキーワード



//基底クラス
class base {
    virtual void func_final() final;
    virtual void func_virt();
    virtual void func_virt_int(int a);
    void func_non_virt();
};

//派生クラス
class derived : public base {
    //NG, final メンバ関数はオーバーライドできない
    void func_final();

    //OK, オーバーライドできている
    void func_virt() override;

    //NG, 引数の個数、型が違っており、オーバーライドできてない
    void func_virt_int(short a) override;

    //NG, 基底クラスの func_non_virt() は仮想関数では無いので、オーバーライドできていない
    void func_non_virt() override;
};




//オーバーライド不可の基底クラス
class base_f final {
    virtual void func_virt();
};

//派生クラス
class derived_f : public base_f {
    //NG, final 基底クラスのメンバ関数はオーバーライドできない
    void func_virt();
};
