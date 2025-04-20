(* Function to calculate the mean (average) of a list of integers *)
let mean lst =
  (* Convert each int to float, sum all values using fold_left *)
  let total = List.fold_left ( +. ) 0.0 (List.map float_of_int lst) in
  total /. float_of_int (List.length lst)  (* Divide total by number of elements *)

(* Function to calculate the median (middle value) of a list *)
let median lst =
  let sorted = List.sort compare lst in  (* Sort the list *)
  let len = List.length sorted in
  if len mod 2 = 0 then
    (* If even number of elements, average the two middle values *)
    let mid1 = List.nth sorted (len/2 - 1) in
    let mid2 = List.nth sorted (len/2) in
    float_of_int (mid1 + mid2) /. 2.0
  else
    (* If odd, return the middle value *)
    float_of_int (List.nth sorted (len/2))

(* Function to calculate the mode(s) (most frequent value(s)) *)
let mode lst =
  (* Create a frequency list using fold_left *)
  let freqs =
    List.fold_left (fun acc x ->
      let count = try List.assoc x acc + 1 with Not_found -> 1 in
      (x, count) :: List.remove_assoc x acc  (* Update count or insert new *)
    ) [] lst
  in
  (* Find the highest frequency count *)
  let max_count = List.fold_left (fun acc (_, c) -> max acc c) 0 freqs in
  (* Filter and collect all values with that max frequency *)
  List.fold_left (fun acc (v, c) -> if c = max_count then v :: acc else acc) [] freqs

(* Main block to test the functions *)
let () =
  let nums = [1; 3; 3; 6; 7; 8; 9] in  (* Sample data *)
  Printf.printf "Mean: %.2f\n" (mean nums);      (* Print mean with 2 decimals *)
  Printf.printf "Median: %.2f\n" (median nums);  (* Print median with 2 decimals *)
  Printf.printf "Mode: ";
  List.iter (Printf.printf "%d ") (mode nums);   (* Print each mode value *)
  print_newline ()  (* Print a newline at the end *)
