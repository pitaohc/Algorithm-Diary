#pragma once
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

#include "List.h"
#include "util.h"
#include "Tree.h"
#include <semaphore>
#include <condition_variable>
using namespace std;
class H2O {
private:
    counting_semaphore<2> sem_h;
    counting_semaphore<2> sem_o;

public:
    H2O():sem_h(2), sem_o(0) {

    }

    void hydrogen(function<void()> releaseHydrogen) {
        sem_h.acquire(); // ��Ҫһ��h��λ�ã�����sem_h�ĳ�ʼֵΪ2�����Կ��Ա�֤������h��λ��
        releaseHydrogen();
        sem_o.release(); // �ͷ�һ��o��λ��
    }

    void oxygen(function<void()> releaseOxygen) {
        //��Ҫ�������o��λ�ã���ζ����ִ��releaseOxygen֮ǰ��ִ��������hydrogen
        sem_o.acquire();
        sem_o.acquire();
        releaseOxygen();
        //�ͷ�����h��λ��
        sem_h.release();
        sem_h.release();
    }
};

