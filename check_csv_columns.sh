#!/bin/bash

# Script to check CSV files for consistent column counts

CSV_DIR="/home/smalley/akadata-amiga-io/platforms/amiga/registers"

echo "Checking CSV files for consistent column counts..."

for csvfile in "$CSV_DIR"/*.csv; do
    echo "Checking: $csvfile"
    
    # Count columns in header (first line)
    header_cols=$(head -n 1 "$csvfile" | tr ',' '\n' | wc -l)
    echo "  Header has $header_cols columns"
    
    # Check each line for consistent column count
    line_num=1
    while IFS= read -r line; do
        line_cols=$(echo "$line" | tr ',' '\n' | wc -l)
        if [ "$line_cols" -ne "$header_cols" ]; then
            echo "  ERROR: Line $line_num has $line_cols columns (expected $header_cols)"
            echo "    Content: $line"
        fi
        ((line_num++))
        
        # Limit to first 100 lines to avoid long processing
        if [ "$line_num" -gt 100 ]; then
            break
        fi
    done < "$csvfile"
    
    echo ""
done

echo "Check complete."