#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

template<typename T>
void Advance(T& iter, const int& distance){
    if(distance>0){
        for(int i=0;i<distance;i++){
            iter++;
        }
    }
    else{
        for(int i=0;i>distance;i--){
            iter--;
        }
    }
    // iter = iter + distance;
}

template<typename T>
int Distance(T iter_1, T iter_2){
    int result = 0;
    while(iter_1 != iter_2){
        iter_1++;
        result += 1;
    }
    return result;
}

template<typename T>
auto Begin(T container)->decltype(container.Begin()){
    return container.Begin();
}

template<typename T>
auto End(T container)->decltype(container.End()){
    return container.End();
}

template<typename T>
T Prev(T iter){
    iter--;
    return iter;
}

template<typename T>
T Next(T iter){
    iter++;
    return iter;
}

#endif // FUNCTION_H_INCLUDED
