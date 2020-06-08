// mathModuleTemplate.ixx

export module math;    

export namespace math {         

    template <typename T, typename T2>
    auto sum(T fir, T2 sec) { 
        return fir + sec;
    }

}
