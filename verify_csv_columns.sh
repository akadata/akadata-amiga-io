#!/bin/bash

# Script to verify column count consistency in CSV files

CSV_FILE="/home/smalley/akadata-amiga-io/platforms/amiga/registers/amiga_registers_corrected.csv"

echo "Verifying column count consistency in: $CSV_FILE"

# Count columns in header (first line)
header_cols=$(head -n 1 "$CSV_FILE" | awk -F',' '{print NF}')
echo "Header has $header_cols columns: $(head -n 1 "$CSV_FILE")"

# Check each line for consistent column count
line_num=1
total_lines=$(wc -l < "$CSV_FILE")
errors_found=0

while IFS= read -r line; do
    line_cols=$(echo "$line" | awk -F',' '{print NF}')
    if [ "$line_cols" -ne "$header_cols" ]; then
        echo "ERROR: Line $line_num has $line_cols columns (expected $header_cols)"
        echo "  Content: $line"
        ((errors_found++))
    fi
    ((line_num++))
done < "$CSV_FILE"

echo ""
echo "Verification complete:"
echo "  Total lines checked: $total_lines"
echo "  Errors found: $errors_found"
if [ "$errors_found" -eq 0 ]; then
    echo "  Result: SUCCESS - All lines have consistent column count!"
else
    echo "  Result: FAILED - Column count inconsistencies found"
fi