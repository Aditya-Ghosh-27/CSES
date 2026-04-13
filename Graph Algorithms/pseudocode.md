/*

requestElevator(floor, type)
    // validate the floor
    if floor < 0 || floor > 9
        return false 
        
    if type == DESTINATION
        return false 
        
    request = Request(floor, type)
    best = selectBestElevator(request)
    return best.addRequest(request)
    




selectBestElevator(request)
    best = findCommittedToFloor(request)
    if best != null 
        return false 
        
    best = findNearestIdle(request.getFloor())
    if best != null 
        return false 
        
    return findNearest(request.getFloor())
    




findCommittedToFloor(request)
    floor = request.getFloor()
    direction = (request.getType() == PICKUP_UP) ? UP : DOWN
    nearest = null 
    minDistance = Integer.MAX_VALUE
    
    for e in elevators
        if e.getDirection() != direction
            continue 
            
        if (direction == UP && e.getCurrentFloor() > floor) || 
           (direction == DOWN && e.getCurrentFloor < floor)
           continue 
           
        if !e.hasRequestAtOrBeyond(floor, type)
            continue
            
        distance = (e.getCurrentFloor() - floor)
        if distance < minDistance
            minDistance = distance 
            nearest = e 
            
    return nearest
    
    
    
    
