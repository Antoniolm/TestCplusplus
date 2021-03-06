// *********************************************************************
// **
// ** Copyright (C) 2017-2018 Antonio David López Machado
// **
// ** This program is free software: you can redistribute it and/or modify
// ** it under the terms of the GNU General Public License as published by
// ** the Free Software Foundation, either version 3 of the License, or
// ** (at your option) any later version.
// **
// ** This program is distributed in the hope that it will be useful,
// ** but WITHOUT ANY WARRANTY; without even the implied warranty of
// ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// ** GNU General Public License for more details.
// **
// ** You should have received a copy of the GNU General Public License
// ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
// **
// *********************************************************************

#include "consumer.h"

Consumer::Consumer(){

}

//************************************************//

Consumer::~Consumer(){
  if (thread.joinable())
    thread.join();
}

//************************************************//

void Consumer::run(){

  for(unsigned i=0;i<num_items;i++){

    sem_wait(consumerSem);

      sem_wait(mutex);
        --(*firstEmptyCell);
        cout<< "Consuming - "<<vector[(*firstEmptyCell)]<<endl;
      sem_post(mutex);

    sem_post(producerSem);
  }
}
