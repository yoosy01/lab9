#include "dayOfYearPtr.h"
#include <memory>
int main()
{
    using namespace YooSeoyoung2693186;
    dayOfYearPtr dp1{dayOfYear{11,5}}; dp1.print();
    dayOfYearPtr dp2{dp1}; dp2.print();
    dayOfYearPtr dp3{std::move(dp2)}; dp2.print(); dp3.print();
    dp2 = std::move(dp3);
    dp3 = dp2;
    dayOfYearPtr* dp{ new dayOfYearPtr{dayOfYear{11,5}} };
    delete dp;

    
    auto up2{ std::make_unique<dayOfYearPtr>(dayOfYear{11,5}) };
    std::unique_ptr<dayOfYearPtr> up1;
    up1 = std::move(up2); up1->print();

    auto sp1{std::make_shared<dayOfYearPtr>(dayOfYearPtr{dayOfYear{12,5}})};
    std::cout << sp1.use_count() << std::endl;
    std::shared_ptr<dayOfYearPtr> sp2{sp1};
    std::cout << sp1.use_count() << " " << sp2.use_count() << std::endl;

    std::weak_ptr<dayOfYearPtr> wp1{sp1};
    std::cout << sp1.use_count() << " " << sp2.use_count() << std::endl;

    sp1.reset();
    std::cout << sp1.use_count() << " " << sp2.use_count() << std::endl;

    if (!wp1.expired()) sp1 = wp1.lock();
    std::cout << sp1.use_count() << " " << sp2.use_count() << std::endl;
    
    return 0;
}