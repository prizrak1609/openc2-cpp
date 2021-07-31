#pragma once

namespace OC {

    class Validation
    {
        public:
            Validation() = default;
            virtual ~Validation() = default;

            virtual bool isValid() = 0;
    };

}
